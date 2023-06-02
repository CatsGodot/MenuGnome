//
//  TestMenus.hpp
//  MenuGnome
//
//  Created by Grant Guenther on 6/1/23.
//
//=======================================================================================
//---------------------------------------------------------------------------------------

#ifndef TestMenus_hpp
#define TestMenus_hpp

//---------------------------------------------------------------------------------------

#include "MenuGnome.hpp"

//---------------------------------------------------------------------------------------

class TestMenu_Main : public MenuGnome
{
	public :
		TestMenu_Main();
	
		virtual void createMenu( MenuDeckGnome *deck );
		virtual int reactToUserChoice( const char szUserChoice[] );
};

//---------------------------------------------------------------------------------------

class TestMenu_Inner : public MenuGnome
{
	public :
		TestMenu_Inner();
		
		virtual void createMenu( MenuDeckGnome *deck );
		virtual int reactToUserChoice( const char szUserChoice[] );
};

//---------------------------------------------------------------------------------------

#endif /* TestMenus_hpp */

//---------------------------------------------------------------------------------------
//=======================================================================================
