 #include "Controller.h"
#include <cmath>
#pragma once
//--------------------------------------------------------//

//main loop of the game

Controller::Controller()
:m_Game_Window(sf::VideoMode(1920, 1080), "Game") {
	
	set_G_O_Vector(); 
	swap_Location();
}
void Controller:: start_Game() {
	sf::Texture background;
	background.loadFromFile("background.png");
	sf::Sprite bg;
	bg.setTexture(background);

	//=============game loop==========================
	while (m_Game_Window.isOpen()) {

		sf::Time elapsed = m_Clock.getElapsedTime();
		m_Game_Window.clear();
		if (elapsed.asSeconds() > 0.05f) {
			int i = 1;
			int array[4] = { sf::Keyboard::Left,sf::Keyboard::Right,sf::Keyboard::Up,sf::Keyboard::Down };
			int current;
			while (i <= m_Enemys) {

				current = array[rand() % 4];
				int enemy_Loc = m_All_Objects.size() - 1 - i;
				(m_All_Objects[enemy_Loc])->effect(&current, m_All_Objects);
				free_fall(enemy_Loc);
				free_fall(m_All_Objects.size()-1);
				i++;
			}
			m_Clock.restart();
		}
		m_Game_Window.draw(bg);
	//	m_Game_Window.clear();
		for (int i = 0; i < m_All_Objects.size(); i++)
			m_All_Objects[i]->draw_On_Board(m_Game_Window);
		m_Game_Window.display();
		sf::Event event;
		while (m_Game_Window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				m_Game_Window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				
				int player_place=m_All_Objects.size()-1;
				
				
				
				(m_All_Objects[player_place])->effect(&(event.key.code),m_All_Objects);
				//free_fall(player_place);
				
				
			}

		}
	
	
	
	}
}
//--------------------------------------------------------//
//setting the game controller vector
void Controller::set_G_O_Vector(){

	sf::Vector2f start_Of_Map(300,100);//start location
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
		sf::RectangleShape cur_Rec(block_Size);
		cur_Rec.setPosition(sf::Vector2f(start_Of_Map.x + j * 1280/ sizeof_Map.x,
			start_Of_Map.y + (i-1) * 720 / sizeof_Map.y));
		
		cur_Rec.setOrigin(sf::Vector2f(cur_Rec.getGlobalBounds().width / 2, cur_Rec.getGlobalBounds().height / 2));
		switch (m_Board.what_In_Location(sf::Vector2i(i, j))) {
		case player:
			name = "����player.png";
			cur_Rec.setSize(player_Size);
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
		//settin the origin again because size is different
			cur_Rec.setOrigin(sf::Vector2f(cur_Rec.getGlobalBounds().width / 2, cur_Rec.getGlobalBounds().height / 2));
			object = new Player(cur_Rec, player);

			break;
		case money:
			name = "money.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Money(cur_Rec, money);
			break;
		case wall:
			name = "wall.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setOutlineThickness(1);
			cur_Rec.setOutlineColor(sf::Color::Black);
			object = new Wall(cur_Rec, wall);

			break;
		case smart:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setSize(player_Size);
			object = new Enemy(cur_Rec, smart);
			break;
		case stupid:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setSize(player_Size);
			object = new Enemy(cur_Rec, stupid);
			break;
		case med:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setSize(player_Size);
			object = new Enemy(cur_Rec, med);
			break;
		case gift:
			name = "money.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, gift);
			break;
		case pole:
			name = "pole.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setSize(sf::Vector2f(block_Size.x, (block_Size.y)/2));
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, pole);
			break;
		case ladder:
			name = "ladder.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, ladder);
			break;
		
		case ' ':
			j++;
			continue;
		};
				m_All_Objects.push_back(object);
				j++;
	}
	i++;

}

}

//----------------------------------------------------------------------------------------------//
//function to make sure the players or the enemys will be printed last 

void Controller::swap_Location() {
	int loc_Of_Player = m_All_Objects.size() - 1, num_of_enemy = 0;;
	int loc_Of_Enemy = loc_Of_Player - 1;
	for (int i = 0;i < loc_Of_Player- num_of_enemy-1;i++) {
		if (m_All_Objects[i]->get_Type() == player) 
			std::swap(m_All_Objects[i], m_All_Objects[loc_Of_Player]);
		if (m_All_Objects[i]->get_Type() == smart) {
			std::swap(m_All_Objects[i], m_All_Objects[loc_Of_Enemy--]);
			num_of_enemy++;
		}
	}
	m_Enemys = num_of_enemy;
	}

//=====================================================================
//function to fall until floor
void  Controller::free_fall(int place)
{
	char floor = What_In_Loc(*m_All_Objects[place]);
	
	
	int key= sf::Keyboard::Down;
	if (floor!=wall&&floor!=ladder&&floor!=pole && floor != money)
		m_All_Objects[place]->effect(&key,m_All_Objects);
		
}										
//=====================================================================
char Controller::What_In_Loc(Game_Object& object)
{
	
	char type = space;
	sf::RectangleShape temp(object.get_rectangle());
	temp.move(0, 5.0f);
	for (int i = 0; i < m_All_Objects.size() ; i++)
	{

		if (temp.getGlobalBounds().intersects(m_All_Objects[i]->get_rectangle().getGlobalBounds())
			&&m_All_Objects[i]->get_Type()!=object.get_Type())
		{
			return type = m_All_Objects[i]->get_Type();
		}										
	}

	return space;
}
//===================================================================