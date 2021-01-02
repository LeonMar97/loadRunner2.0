 #include "Controller.h"
#pragma once
//--------------------------------------------------------//

//main loop of the game

Controller::Controller()
:m_Game_Window(sf::VideoMode(1920, 1080), "Game") {
	
	set_G_O_Vector(); 
}
void Controller:: start_Game() {
	
	while (m_Game_Window.isOpen()) {
		m_Game_Window.clear();
		for (int i = 0; i < m_All_Objects.size(); i++)
			m_All_Objects[i]->draw_On_Board(m_Game_Window);
		m_Game_Window.display();
		sf::Event event;
		while (m_Game_Window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				m_Game_Window.close();
		}
	
	
	
	}
}
//--------------------------------------------------------//
//setting the game controller vector
void Controller::set_G_O_Vector(){

	sf::Vector2f start_Of_Map(0,0);//start location
sf::Texture* pic;
sf::Vector2i sizeof_Map;
sizeof_Map = m_Board.get_Size();
//float sizeof_Angle=((1280*720)/(sizeof_Map.x* sizeof_Map.y));//seting the size of angle of each
															//block of the texture

//sf::Vector2f block_Size(sizeof_Angle,sizeof_Angle);
sf::Vector2f block_Size(1280/sizeof_Map.x, 720/sizeof_Map.y);
int i = 1,j=0;
std::string name;
Game_Object * object;
while (i < sizeof_Map.y+1) {
	j = 0;
	while (j < sizeof_Map.x) {
		sf::RectangleShape cur_Rec(block_Size);
		cur_Rec.setPosition(start_Of_Map.x + j * 1280/ sizeof_Map.x,
			start_Of_Map.y + (i-1) * 720 / sizeof_Map.y);

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
			object = new Wall(cur_Rec, wall);

			break;
		case smart:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Enemy(cur_Rec, smart);
			break;
		case stupid:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Enemy(cur_Rec, stupid);
			break;
		case med:
			name = "enemy.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
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
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, gift);
			break;
		case ladder:
			name = "ladder.png";
			pic = new sf::Texture;
			pic->loadFromFile(name);
			cur_Rec.setTexture(pic);
			object = new Gift(cur_Rec, gift);
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


	