 #include "Controller.h"
#include <cmath>
#include <experimental/vector>
#include <sstream>
#include <string>

#pragma once
//--------------------------------------------------------//

//main loop of the game

Controller::Controller()
:m_Game_Window(sf::VideoMode(1920, 1080), "Game") {
	load_pic();// all the loaded pictures located in vector
	set_G_O_Vector(); 
	//swap_Location();
}
void Controller:: start_Game() {
	set_Background_And_Score();//setting everything before the start
	sf::Music music;
	music.openFromFile("theme song.ogg");
	music.play();
	music.setVolume(10);
	m_Game_menu.draw(m_Game_Window);

	//=============game loop==========================
	while (m_Game_Window.isOpen())
	{

		m_Game_Window.clear();
		draw_Score_Board();
		draw_Time();
		draw_On_map();
		m_Game_Window.display();
		check_Rest_Time();
		sf::Event event;
		while (m_Game_Window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				m_Game_Window.close();
		}
		updateGameObjects();
		free_Fall();
		check_Gifts();//getting info after collision with gifts
		check_Hits();
		check_Erace();
		check_Score();



		

	 }
	}

//--------------------------------------------------------//
//setting the game controller vector
void Controller::set_G_O_Vector(){
sf::Texture* pic;
sf::Vector2i sizeof_Map;
sizeof_Map = m_Board.get_Size();
//float sizeof_Angle=((1280*720)/(sizeof_Map.x* sizeof_Map.y));//seting the size of angle of each
															//block of the texture

//sf::Vector2f block_Size(sizeof_Angle,sizeof_Angle);
sf::Vector2f block_Size(1280/sizeof_Map.x, 720/sizeof_Map.y);
sf::Vector2f player_Size(900 / sizeof_Map.x, 600 / sizeof_Map.y);

int i = 1,j=0;
std::string name;
Game_Object * object;
while (i < sizeof_Map.y+1) {
	j = 0;
	while (j < sizeof_Map.x) {
//----------------------creating block and setting their size--------------------------------------------------
		sf::RectangleShape cur_Rec(block_Size);
		sf::Vector2f rec_Loc(sf::Vector2f(start_Of_Map.x + j * 1280 / sizeof_Map.x,
			start_Of_Map.y + (i - 1) * 720 / sizeof_Map.y));
		cur_Rec.setPosition(rec_Loc);

		cur_Rec.setOrigin(sf::Vector2f(cur_Rec.getGlobalBounds().width / 2, cur_Rec.getGlobalBounds().height / 2));
//----------------------

		switch (m_Board.what_In_Location(sf::Vector2i(i, j))) {
		case player:
			cur_Rec.setSize(player_Size);
		//settin the origin again because size is different
			cur_Rec.setOrigin(sf::Vector2f(cur_Rec.getGlobalBounds().width / 2, cur_Rec.getGlobalBounds().height / 2));
			object = new Player(cur_Rec, rec_Loc);
			m_All_Objects[players].push_back(object);
			break;
		case money:
			object = new Money(cur_Rec, rec_Loc);
			m_All_Objects[moneys].push_back(object);
			break;
		case wall:
			object = new Wall(cur_Rec, rec_Loc);
			m_All_Objects[walls].push_back(object);
			break;
		case enemy:
			cur_Rec.setSize(player_Size);
			// settin the origin again because size is different
			
			srand(rand());
			//randomizing enemys
			switch ((rand() % 4) + 1) {
				

			case 1:	object = new Smart_Enemy(cur_Rec, rec_Loc);
				m_All_Objects[enemys].push_back(object);
				break;
			case 2:
				object = new Med_Enemy(cur_Rec, rec_Loc);
				m_All_Objects[enemys].push_back(object);
				break;
			case 3:
				object = new Stupid_Enemy(cur_Rec, rec_Loc);
				m_All_Objects[enemys].push_back(object);
				break;

				};

		
			break;
	
		case gift:
			object = new Gift(cur_Rec, rec_Loc);
			m_All_Objects[gifts].push_back(object);
			break;
		case pole:
			cur_Rec.setSize(sf::Vector2f(block_Size.x, (block_Size.y)/2));
			object = new Pole(cur_Rec, rec_Loc);
			m_All_Objects[poles].push_back(object);
			break;
		case ladder:
			object = new Ladder(cur_Rec, rec_Loc);
			m_All_Objects[ladders].push_back(object);
			break;		
		case ' ':
			j++;
			continue;
		};
		j++;
				
	}
	i++;

}

}

//----------------------------------------------------------------------------------------------//
//has to be here so you could see the player falling 
//function calls every second to check if all the players/enemys falling
void  Controller::free_Fall()
{
	for (int i = enemys;i <= players;i++) {
		for (int j = 0;j < m_All_Objects[i].size();j++) {
			dynamic_cast<Moving_Object*>(m_All_Objects[i][j])->on_Floor(m_All_Objects);
		}
	}


}
//----------------------------------------------------------------------------------------------//
//draws all the elements each time
void Controller :: draw_On_map() {
	
	for (int i = 0;i <NUM_OF_OBJECTS;i++)
	{
		for (int j = 0;j < m_All_Objects[i].size();j++) {
			m_All_Objects[i][j]->draw_On_Board(m_Game_Window);
		}
	}
}
//=====================================================================
//loadding all the pictures to save runtime
void Controller::load_pic() {
	std::vector<std::string>names[] = {
						  {"wall.png"},
						  {"ladder.png"},
						  {"pole.png"},
						  {"money.png"},
						  {"gift.png"},
						  {"enemy.png"},
						  {"player.png","secondwall.png"} };

	int i, j;
	sf::Texture *pic;
	for (i = walls; i < NUM_OF_OBJECTS; i++) {
		for (j = 0; j < names[i].size(); j++) {
			pic = new sf::Texture;
			pic->loadFromFile(names[i][j]);
			m_All_textures[i].push_back(pic);
		}

	}
}


//=====================================================================

void Controller::updateGameObjects()
{
	 auto deltaTime = m_Clock.restart();

	m_All_Objects[players][0]->effect(&deltaTime,m_All_Objects);
}
//============================================================
//erase money and gift
void Controller::draw_Score_Board() {
	m_Scoreboard_Text[sc].setString(std::to_string((dynamic_cast<Player*>(m_All_Objects[players][0]))->getscore()));
	m_Scoreboard_Text[lvl].setString(std::to_string(m_Lvl));
	m_Scoreboard_Text[lf].setString(std::to_string((dynamic_cast<Player*>(m_All_Objects[players][0]))->getlives()));
	m_Game_Window.draw(m_bg);
	m_Game_Window.draw(m_Score_Board);
	for (int i = 0; i <= lf; i++) {
		m_Game_Window.draw(m_Scoreboard_Text[i]);
	}
	
}
//============================================================

void Controller:: check_Erace() {
	std::experimental::erase_if(m_All_Objects[moneys], [](auto const& item)
		{
			return dynamic_cast<Disappearing_Object*>(item)->get_deleted();
		});
	std::experimental::erase_if(m_All_Objects[gifts], [](auto const& item)
		{
			return dynamic_cast<Disappearing_Object*>(item)->get_deleted();
		});


}
void Controller::set_Background_And_Score() {


	//------------------------setting scoreboard and background--------------------------
	sf::Texture *background=new sf::Texture();
	sf::Texture* scoreBoard_pic = new sf::Texture();
	background->loadFromFile("background2.png");
	scoreBoard_pic->loadFromFile("scoreBoard.png");
	m_bg.setTexture(*background);
	m_Score_Board.setTexture(scoreBoard_pic);
	m_Score_Board.setSize(sf::Vector2f(300.0f, 250.0f));
	m_Score_Board.setPosition(m_bg.getGlobalBounds().width / 2 -
		m_Score_Board.getGlobalBounds().width / 2, start_Of_Map.y + 700);

	//------------------------setting font--------------------------	
	sf::Font *font=new sf::Font() ;
	float s = m_Score_Board.getGlobalBounds().height / 5;
	font->loadFromFile("Love America.ttf");
		for (int i = 0; i <= lf; i++) {

			m_Scoreboard_Text[i].setPosition(m_Score_Board.getPosition().x + m_Score_Board.getGlobalBounds().width / 2,
				m_Score_Board.getPosition().y + ((s)*(i + 1) + (i*s) / 2));

		m_Scoreboard_Text[i].setFont(*font);
		m_Scoreboard_Text[i].setFillColor(sf::Color::Red);
		m_Scoreboard_Text[i].setCharacterSize(24);
		m_Scoreboard_Text[i].setStyle(sf::Text::Bold | sf::Text::Underlined);
		}
		time_to_screen.setFont(*font);
		time_to_screen.setPosition(750, 20);
		time_to_screen.setFillColor(sf::Color::Blue);
		time_to_screen.setCharacterSize(40);
		time_to_screen.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
}
//=========================================================================
//checking if player got hit by enemy and reset lvl without coins
void Controller::check_Hits()
{
	
	if (dynamic_cast<Player*>((m_All_Objects[players][0]))->get_hit())
	{
		for (int i = 0; i < NUM_OF_OBJECTS; i++)
		{
			for (int j = 0; j < m_All_Objects[i].size(); j++) {
				sf::Vector2f first_Loc(m_All_Objects[i][j]->get_First_loc());
				m_All_Objects[i][j]->set_loction(first_Loc);

			}

		}
	}
	dynamic_cast<Player*>((m_All_Objects[players][0]))->set_hit(false);
}
//=========================================================================
//checking info from gift
void Controller::check_Gifts() {
	for (int i = 0; i < m_All_Objects[gifts].size(); i++) {

		if (dynamic_cast<Gift*>((m_All_Objects[gifts][i]))->get_Bad_Gift()) {
			
			Enemy* vasia = new Enemy(*dynamic_cast<Enemy*>(m_All_Objects[enemys][0]));
			sf::Vector2f fir(m_All_Objects[players][0]->get_First_loc());
			vasia->set_loction(fir);
			m_All_Objects[enemys].push_back(vasia);
		}
		if (dynamic_cast<Gift*>((m_All_Objects[gifts][i]))->get_time_Gift())
		{
			m_Board.set_time(m_Board.get_Time() +EXTRA_TIME);
		}
	

	}
}
//=========================================================================
void Controller::delete_vector()
{
	for (int i = 0; i < NUM_OF_OBJECTS; i++)
	{
			m_All_Objects[i].clear();
	}
	m_All_Objects->clear();
}
//=========================================================================
//resting the time
void Controller:: check_Rest_Time() {
	sf::Time elapsed = m_Game_Clock.getElapsedTime();
	if ((int)elapsed.asSeconds() > m_Board.get_Time()) {
		m_Game_Clock.restart();
		int lif = (dynamic_cast<Player*>(m_All_Objects[players][0])->getlives()) - 1;
		int score = (dynamic_cast<Player*>(m_All_Objects[players][0])->getscore());
		delete_vector();
		set_G_O_Vector();
		
		dynamic_cast<Player*>(m_All_Objects[players][0])->
			setscore(m_Player_enter_score);
	
		dynamic_cast<Player*>(m_All_Objects[players][0])->setlives(lif);
		m_Game_Clock.restart();

	}
	
	
		for (int i = 0; i < m_All_Objects[walls].size(); i++)
		{
			dynamic_cast<Wall*>(m_All_Objects[walls][i])->Check_Wall
			(*(Player*)(m_All_Objects[players][0]));
		}
	

}
//=========================================================================
void Controller::draw_Time() {
	sf::Time elapsed = m_Game_Clock.getElapsedTime();
	std::stringstream time;
	time << "Time left   [00:" << std::to_string(m_Board.get_Time() - (int)elapsed.asSeconds())<<"]";
	time_to_screen.setString(time.str());
	m_Game_Window.draw(time_to_screen);
}
//=====================================================================
void Controller::check_Score() {
	if (m_All_Objects[moneys].size() == 0) {
		m_Board.rebuild_Map();
		m_Lvl++;
		m_Player_enter_score = (dynamic_cast<Player*>(m_All_Objects[players][0]))->getscore();
		m_Player_enter_score += 50;
		delete_vector();
		set_G_O_Vector();
		dynamic_cast<Player*>(m_All_Objects[players][0])->setscore(m_Player_enter_score);
		m_Game_Clock.restart();

	}
}