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

#define kuMenuGnome_MaxLenUserChoice						32
#define kuMenuGnome_MaxLenUserPrompt						32
#define kuMenuGnome_MaxLenMenuTitle							32

#define knMenuGnome_InvalidChoice							-1
#define knMenuGnome_EmptyChoice								-2

//---------------------------------------------------------------------------------------

class MenuGnome;
class MenuGnomeActionDelegate;
class MenuDeckGnome
{
	public:
		MenuDeckGnome();
		~MenuDeckGnome();
		
		void addMenuToDeck( MenuGnome *menu );
		void setMenu( int menuID );
		
		void print( void );
		
		int run( void );
		
		virtual void go( MenuGnomeActionDelegate *delegate );
		
	protected:
		const char *presentUserPrompt( char szUserChoice[] );
		int reactToUserChoice( void );
	
		MenuGnome		*menus,
						*current_menu;
		
		char			user_choice[kuMenuGnome_MaxLenUserChoice];
};

//---------------------------------------------------------------------------------------

struct MenuGnome_UserChoice;
class MenuGnome
{
	public:
		MenuGnome( int menuID, const char title[], const char userPrompt[] );
		virtual ~MenuGnome();
		
		virtual void createMenu( void ) = 0;
		virtual void addUserChoice( MenuGnome_UserChoice *userChoice );
		virtual void addNewUserChoice( int nActionValue, 
											const char szMenuOption[],
											const char szMenuOptionFull[] );
		void addEmptyUserChoice( void );
		virtual int reactToUserChoice( const char szUserChoice[] );
		
		MenuGnome_UserChoice *createUserChoice( int nActionValue, 
													const char szMenuOption[],
													const char szMenuOptionFull[] );
		
		void print( void );
		
		int menuID( void );
		
	protected:
		MenuGnome_UserChoice	*choices;
		int						menu_id;
		char					title[kuMenuGnome_MaxLenMenuTitle],
								user_prompt[kuMenuGnome_MaxLenUserPrompt];
		
		MenuGnome				*next;
		
		friend class MenuDeckGnome;
};

//---------------------------------------------------------------------------------------

struct MenuGnome_UserChoice
{
	char					*menu_option;
	char					*menu_option_full;
	int						action_value;
	
	MenuGnome_UserChoice	*next;
};

//---------------------------------------------------------------------------------------

class MenuGnomeActionDelegate
{
	protected:
		virtual bool handleUserAction( int userActionValue );
		virtual bool doDefaultUserAction( int userActionValue );
		
	friend class MenuDeckGnome;
};

//---------------------------------------------------------------------------------------

#endif /* MenuGnome_hpp */

//---------------------------------------------------------------------------------------
//=======================================================================================
