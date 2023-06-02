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
		
		void addMenuToDeck( MenuGnome *menu );
		void setMenu( int menuID );
		
		void print( void );
		
		int run( void );
		
	protected:
		const char *presentUserChoice( void );
		int reactToUserChoice( void );
	
		MenuGnome		*menus,
						*current_menu;
		int				num_menus;
		
		char			szUserChoice[kuMaxLenUserChoice];
};

//---------------------------------------------------------------------------------------

struct MenuGnome_UserChoice;
class MenuGnome
{
	public:
		MenuGnome( int menuID );
		~MenuGnome();
		
		virtual void createMenu( MenuDeckGnome *deck ) = 0;
		virtual void addUserChoice( MenuGnome_UserChoice *userChoice );
		virtual int reactToUserChoice( const char szUserChoice[] );
		
		void print( void );
		
	protected:
		char 					*screen;
		MenuGnome_UserChoice	*choices;
		int						num_choices,
								id;
		
		MenuGnome				*next;
};

//---------------------------------------------------------------------------------------

struct MenuGnome_UserChoice
{
	char					user_choice;
	char					*menu_option;
	int						action_value;
};

//---------------------------------------------------------------------------------------

#endif /* MenuGnome_hpp */

//---------------------------------------------------------------------------------------
//=======================================================================================
