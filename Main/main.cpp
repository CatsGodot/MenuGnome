//
//  main.cpp
//  MenuGnome
//
//  Created by Grant Guenther on 6/1/23.
//
//=======================================================================================
//---------------------------------------------------------------------------------------

#include "TestMenus.hpp"

//---------------------------------------------------------------------------------------

int main(int argc, const char * argv[]) 
{
	MenuDeckGnome				menu_deck;
	
	TestMenu_Main				*main_menu = new TestMenu_Main();
	TestMenu_Inner				*inner_menu = new TestMenu_Inner();
	
	menu_deck.addMenuToDeck(main_menu);
	menu_deck.addMenuToDeck(inner_menu);
	
	while ( -1 != menu_deck.run() ) ;
	
	return 0;
}

//---------------------------------------------------------------------------------------
//=======================================================================================
