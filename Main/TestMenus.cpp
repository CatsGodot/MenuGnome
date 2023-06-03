//
//  TestMenus.cpp
//  MenuGnome
//
//  Created by Grant Guenther on 6/1/23.
//
//=======================================================================================
//---------------------------------------------------------------------------------------

#include "TestMenus.hpp"

//---------------------------------------------------------------------------------------

TestMenu_Main::TestMenu_Main() : MenuGnome( 0, "MAIN MENU", "Select a menu option  --> ")
{
}	

//---------------------------------------------------------------------------------------
	
void TestMenu_Main::createMenu( void )
{
	MenuGnome_UserChoice				*wNewMenu;
	
	this->addEmptyUserChoice();
	wNewMenu = this->createUserChoice( 10, "0", "[0] Enter Inner Menu");
	this->addUserChoice( wNewMenu );
	this->addEmptyUserChoice();
	wNewMenu = this->createUserChoice( 0, "X", "E [X] it");
	this->addUserChoice( wNewMenu );
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------

TestMenu_Inner::TestMenu_Inner() : MenuGnome( 1, "INNER MENU", "Select a menu option  --> ")
{
}	

//---------------------------------------------------------------------------------------
	
void TestMenu_Inner::createMenu( void )
{
	MenuGnome_UserChoice				*wNewMenu;
	
	this->addEmptyUserChoice();
	wNewMenu = this->createUserChoice( 100, "B", "Go [B] ack");
	this->addUserChoice( wNewMenu );
}

//---------------------------------------------------------------------------------------
//=======================================================================================
