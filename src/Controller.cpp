 #include "Controller.h"
#include <cmath>
#pragma once
//--------------------------------------------------------//

//main loop of the game

Controller::Controller()
:m_Game_Window(sf::VideoMode(1920, 1080), "Game") {
	
	set_G_O_Vector(); 
	//swap_Location();
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
	/*
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
		*/
			m_Game_Window.draw(bg);
	//	m_Game_Window.clear();
		
				 draw_On_map();
				m_Game_Window.display();
		sf::Event event;
		while (m_Game_Window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
				m_Game_Window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				
				//int player_place=m_All_Objects[players];
				
				
				
				(m_All_Objects[players][0])->effect(&(event.key.code),m_All_Objects);
				
				
				
			}

		}
	
		free_Fall();
	
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
			name = "þþþþplayer.png";
			cur_Rec.setSize(player_Size);
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
		//settin the origin again because size is different
			cur_Rec.setOrigin(sf::Vector2f(cur_Rec.getGlobalBounds().width / 2, cur_Rec.getGlobalBounds().height / 2));
			object = new Player(cur_Rec, player);
			m_All_Objects[players].push_back(object);
			break;
		case money:
			name = "money.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Money(cur_Rec, money);
			m_All_Objects[disappear].push_back(object);
			break;
		case wall:
			name = "wall.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setOutlineThickness(1);
			cur_Rec.setOutlineColor(sf::Color::Black);
			object = new Wall(cur_Rec, wall);
			m_All_Objects[walls].push_back(object);
			break;
		case smart:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setSize(player_Size);
			object = new Enemy(cur_Rec, smart);
			m_All_Objects[enemys].push_back(object);
			break;
		case stupid:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setSize(player_Size);
			object = new Enemy(cur_Rec, stupid);
			m_All_Objects[enemys].push_back(object);
			break;
		case med:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			cur_Rec.setSize(player_Size);
			object = new Enemy(cur_Rec, med);
			m_All_Objects[enemys].push_back(object);
			break;
		case gift:
			name = "money.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, gift);
			m_All_Objects[disappear].push_back(object);
			break;
		case pole:
			name = "pole.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setSize(sf::Vector2f(block_Size.x, (block_Size.y)/2));
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, pole);
			m_All_Objects[poles].push_back(object);
			break;
		case ladder:
			name = "ladder.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, ladder);
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



