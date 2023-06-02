//
//  MenuGnome.hpp
//  MenuGnome
//
//  Created by Grant Guenther on 6/1/23.
//
//=======================================================================================
//---------------------------------------------------------------------------------------

#ifndef MenuGnome_hpp
#define MenuGnome_hpp

//---------------------------------------------------------------------------------------

#include <stdio.h>

//---------------------------------------------------------------------------------------

#define kuMaxLenUserChoice						32

//---------------------------------------------------------------------------------------

class MenuGnome;
class MenuDeckGnome
{
	public:
		MenuDeckGnome();
		~MenuDeckGnome();
		
	protected:
		void addMenuToDeck( MenuGnome *menu );
	
		MenuGnome		*menus;
		int				num_menus;
		
		char			szUserChoice[kuMaxLenUserChoice];
};

//---------------------------------------------------------------------------------------

class MenuGnome
{
	public:
		MenuGnome();
		~MenuGnome();
		
		virtual void createMenu( MenuDeckGnome *deck );
		virtual int reactToMenuChoice( const char szUserChoice[] );
		
	protected:
		char 				*screen;
		int					id;
		
		MenuGnome			*next;
};

//---------------------------------------------------------------------------------------

#endif /* MenuGnome_hpp */

//---------------------------------------------------------------------------------------
//=======================================================================================
