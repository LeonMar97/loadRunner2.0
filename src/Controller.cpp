 #include "Controller.h"
#pragma once
//--------------------------------------------------------//

//main loop of the game


void Controller:: start_Game() {

	


	while (m_Game_Window.isOpen()) {
		m_Game_Window.clear();
		for (int i = 0; i < m_All_Objects.size(); i++)
			m_All_Objects[i]->draw_On_Board(m_Game_Window);
		m_Game_Window.display();

	
	
	
	}
}
//--------------------------------------------------------//
//setting the game controller vector
void Controller::set_G_O_Vector(){

	sf::Vector2f start_Of_Map(0,0);//start location
sf::Texture* pic;
sf::Vector2i sizeof_Map;
sizeof_Map = m_Board.get_Size();
float sizeof_Angle=((1280*720)/(sizeof_Map.x* sizeof_Map.y));//seting the size of angle of each
															//block of the texture
sf::Vector2f block_Size(sizeof_Angle,sizeof_Angle);
int i = 0,j=0;
std::string name;
Game_Object * object;
while (i < sizeof_Map.x) {
	j = 0;
	while (j < sizeof_Map.y) {
		sf::RectangleShape cur_Rec(block_Size);
		cur_Rec.setPosition(start_Of_Map.x + i * sizeof_Angle,
			start_Of_Map.y + j * sizeof_Angle);

		switch (m_Board.what_In_Location(sf::Vector2i(i, j))) {
		case player:
			name = "player.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
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
			object = new Player(cur_Rec, wall);

			break;
		case smart:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Player(cur_Rec, smart);
			break;
		case stupid:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Player(cur_Rec, stupid);
			break;
		case med:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Player(cur_Rec, med);
			break;
		case gift:
			name = "money.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Player(cur_Rec, gift);
			break;
		};

		m_All_Objects.push_back(object);
	}

}
}


	