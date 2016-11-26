#include <iostream>
#include <vector>

using namespace std;


// Student ID: 13006312
// Data Structures and Algorithms

/////
//	- READ ME -
//  - Start at void Main(), this is located at the bottom due to the nature of procedural code
//  - File was required to be singluar for submission, these classes could be put into respective .h/.cpp files for library use.
//	- RE: Pragma
//		Pragram regions are used to condense sections down in visual studio, remove them them if they cause issue with compiler.
//		Pragram region list: "Classes - Pancake", "Classes - Spreads and topping", "Classes - Fillings", "Classes - State pattern"
/////


////////////////////////////////////////////
//-----decorator pattern begins here------//
////////////////////////////////////////////

//Inherited Pancakes (class "Consumables" abstract template for Pancakes or similar potential products e.g crepe.)
#pragma region "Classes - Pancake"
class Consumables
{
public:
	Consumables(){}
	// Constructor: initialised a instance of the class it belongs to, allocating memory for its use.
	// Can be used to initilise class contained variables using parameter list.

	virtual ~Consumables(){} 
	// virtual destructor ensures sub-classes destructor called first.
	// Important: destructor cleans up class it belongs to, freeing up memory used.
	// Important: allows clean up of any dynamically allocated variables through polymorphism.

	virtual void Description(){}
	// virtual Description, allows polymorphism to alter class feedback to specific concrete class.

	virtual int Cost()
	{
		return 10;
	}

};

class NormalPancake : public Consumables // shows LemonPancakes is a (public(access)) Consumable, through inheritance.
{
public:
	NormalPancake(){} // Constructor, required for class initialisation.

	~NormalPancake(){} // Deconstructor, called before parent/abstract class due to virtual in parent/abstract.

	void Description()
	{
		cout << "A normal Pancake."
			<< "\n";
	}
	// Description unique to concrete class, outputs result of Pancake.

	int Cost()
	{
		return int(10);
	}
	// Cost unique to concrete class, outputs cost requirement.
	// Different from abstract class value, due to virtual keyword in parent/abstract class and modified return value.
};

class LemonPancake : public Consumables // shows LemonPancakes is a (public(access)) Consumable, through inheritance.
{
public:
	LemonPancake(){} // Constructor, required for class initialisation.

	~LemonPancake(){} // Deconstructor, called before parent/abstract class due to virtual in parent/abstract.

	void Description()
	{
		cout << "A Lemon flavoured Pancake." 
			 << "\n";
	}
	// Description unique to concrete class, outputs result of Pancake.

	int Cost()
	{
		return 14;
	}
	// Cost unique to concrete class, outputs cost requirement.
	// Different from abstract class value, due to virtual keyword in parent/abstract class and modified return value.
};

class ChocolatePancake : public Consumables
{
public:
	ChocolatePancake(){} // Constructor, required for class initialisation.

	~ChocolatePancake(){} // Deconstructor, called before parent/abstract class due to virtual in parent/abstract.

	void Description()
	{
		cout << "A Chocolate flavoured Pancake."
			<< "\n";
	}
	// Description unique to concrete class, outputs result of Pancake.

	int Cost()
	{
		return 17;
	}
	// Cost unique to concrete class, outputs cost requirement.
	// Different from abstract class value, due to virtual keyword in parent/abstract class and modified return value.
};

#pragma endregion

// Pancake decorator 1; spreads and toppings.
#pragma region "Classes - Spreads and toppings"

// see maple_Syrup_Spread and Nutella_Spreadable for structure comments
class spreadDecorator : public Consumables // shows spreadDecorator is a (public(access)) Consumable, through inheritance.
{
public:
	Consumables* Pancake; 
	// Key Decorator Pattern compositional link, allows allocation of Consumable instance within this abstract sub-class.
	// allows encapsulation of base pancake for "decorating" with additional concrete class method information (belonging to spreadDecorator).
	// pointer allocation means dynamic memory allocation (requires a delete).

	spreadDecorator(){}

	virtual ~spreadDecorator()
	{
		delete Pancake; 
		// De-allocates this class variable Consumable (pointer stores using "new" keyword, delete clean "new" allocation)
		// allowing for cascade of deconstructor calls (cleaning/freeing all encapsulationed layers).
		// delete is called here when this call recieves a delete instruction/keyword.
	}

	void addToConsumables(Consumables* Pancake)
	{
		this->Pancake = Pancake;
	}
	// Method to allocate class of Consumable heritage to the Pancake variable of this class (encapsulating/storing them).

	virtual void Description(){}
	// virtual, polymorphism introduces change of description in sub-classes.

};

class Maple_Syrup_Spread : public spreadDecorator
{
public:
	int Cost()
	{
		return (4 + Pancake->Cost() );
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with a maple syrup spread." 
			 << "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.
};

class Nutella_Spreadable : public spreadDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost() );
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with nutella spread." 
			 << "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class Chocolate_Chip : public spreadDecorator
{
public:
	int Cost()
	{
		return (3 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with chocolate chips."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class Brown_Sugar : public spreadDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with brown sugar."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class Wild_Berry_Spread : public spreadDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with wild berry sauce."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class Jelly_beans : public spreadDecorator
{
public:
	int Cost()
	{
		return (3 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with jelly beans."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class Hundreds_Thous : public spreadDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with 100s and 1000s."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class SmartiesToppings : public spreadDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with smarties."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class ChocolateSpread : public spreadDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with chocolate sauce."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class WildliciousSpread : public spreadDecorator
{
public:
	int Cost()
	{
		return (3 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with wildlicious spread."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class Frosted : public spreadDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Coated with frosting."
			<< "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};
#pragma endregion


// Pancake decorator 2; fillings.
#pragma region "Classes - Fillings"

class fillingDecorator : public Consumables // shows fillingDecorator is a (public(access)) Consumable, through inheritance.
{
public:
	Consumables* Pancake;
	// Key Decorator Pattern compositional link, allows allocation of Consumable instance within this abstract sub-class.
	// allows encapsulation of base pancake for "decorating" with additional concrete class method information (belonging to spreadDecorator).
	// pointer allocation means dynamic memory allocation (requires a delete).

	fillingDecorator()
	{}

	~fillingDecorator()
	{
		delete Pancake;
		// De-allocates this class variable Consumable (pointer stores using "new" keyword, delete clean "new" allocation)
		// allowing for cascade of deconstructor calls (cleaning/freeing all encapsulationed layers).
		// delete is called here when this call recieves a delete instruction/keyword.
	}

	void addToConsumables(Consumables* Pancake)
	{
		this->Pancake = Pancake;
	}
	// Method to allocate class of Consumable heritage to the Pancake variable of this class (encapsulating/storing them).

	virtual void Description(){}
};

class Vanilla_Icecream_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (6 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with vanilla icecream."
			 << "\n";
	}
	// Retained description, despite virtual abstraction in decorator, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.

};

class nutella_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost() );
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with nutella."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Cookie_dough_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (3 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with cookie dough."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Cookies_n_Cream_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with cookies and cream."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Peanut_Butter_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (1 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with peanut butter."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Strawberry_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with strawberry sauce."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Raspberry_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with raspberry sauce."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Cherry_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with cherry sauce."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Blueberry_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with blueberry sauce."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Wild_Berry_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with wild berry sauce."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Vanilla_Cream_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (3 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with vanilla flavoured cream."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Chocolate_Fudge_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (4 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with chocolate fudge."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Fudge_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (4 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with fudge."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

class Chocolate_Filling : public fillingDecorator
{
public:
	int Cost()
	{
		return (2 + Pancake->Cost());
	}
	// adjusted cost, concatenation of int value with stored Pancake Cost, resulting in addition of cost to
	// base cost value, this will consider encapulated layers as well.

	void Description()
	{
		Pancake->Description();
		// Through encapsulation process loses information, points to prior encapsulated class and returns value.
		// allowing for preservation of each encapulated layers description output in sequence.

		cout << "\t" << "Filled with chocolate sauce."
			<< "\n";
	}
	// Retained description, added concrete description.
	// Tabbed to show it belongs to description of base layer encaspulated, base layer doesn't use tabs.


};

#pragma endregion


// Lists, Enum type binds a text value to a numeric value e.g {cat, dog, fish, hamster, ...} {0,1,2,3,4, ...}.
	// used to construct pancakes with meaningful int values.
enum ListPancakes { Normal_Pancake, Lemon_Pancake, Chocolate_Pancake };
enum ListSpreads { Frosted, Wildlicious, Chocolate, Smarties, Hundreds_Thous, Jelly_beans, Wild_Berry, Brown_Sugar, Chocolate_Chip, Maple_Syrup, Nutella_Spread };
enum ListFillings { Chocolate_Fill, Fudge, Chocolate_Fudge, Vanilla_Cream, Wild_Berry_Fill, Blueberry, Cherry, Raspberry, Strawberry, Peanut_Butter, Cookies_n_Cream, Cookie_dough, Vanilla_Icecream, Nutella_Filling };

////////////////////////////////////////////
//*******decorator pattern ends here******//
////////////////////////////////////////////

// Factory Bespoke

// Class is used to create a specific Pancake with an option to add fillings and spreads/toppings.
// Class to be stored in state context to be called when needed in the state pattern.

class resultPancake
{
public:
	Consumables* thisPancake = NULL; // this will be our final pancake from selection
	spreadDecorator* thisSpread = NULL; // handles spreads
	fillingDecorator* thisFilling = NULL; // handles decorators

	// Constructor
	// We allocate a Pancake straight away, allowing for decoration

	resultPancake(int Base_Pancake)
	{
		// create a Pancake as soon as created based on user input
		switch (Base_Pancake)
		{
		case 0:
			thisPancake = new NormalPancake;
			break;

		case 1:
			thisPancake = new LemonPancake;
			break;

		case 2:
			thisPancake = new ChocolatePancake;
			break;

		default:
			cout << "Your Selection is invalid" << "\n";
			break;
		}
	}

	// Deconstructor
	~resultPancake()
	{ 
		delete thisPancake, thisSpread, thisFilling; // clean dynamically allocated memory
	}

	// Add a spread to thisPancake in place (Option parameter uses enum list feature seen in decorator section)
	void addSpread(int option)
	{
		switch (option)
		{
		case 0:
			thisSpread = new class Frosted; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 1:
			thisSpread = new class WildliciousSpread; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 2:
			thisSpread = new class ChocolateSpread; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 3:
			thisSpread = new class SmartiesToppings; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 4:
			thisSpread = new class Hundreds_Thous; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 5:
			thisSpread = new class Jelly_beans; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 6:
			thisSpread = new class Wild_Berry_Spread; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 7:
			thisSpread = new class Brown_Sugar; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 8:
			thisSpread = new class Chocolate_Chip; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 9:
			thisSpread = new class Maple_Syrup_Spread; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;
		case 10:
			thisSpread = new class Nutella_Spreadable; // make a new spread
			thisSpread->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisSpread; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisSpread = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		default:
			// An error message for user
			cout << "Your Selection is invalid" << "\n";
			break;
		}
	}

	// Add a Filling to thisPancake in place (Option parameter uses enum list feature seen in decorator section)
	void addFilling(int option)
	{
		switch (option)
		{
		case 0:
			thisFilling = new class Chocolate_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 1:
			thisFilling = new class Fudge_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 2:
			thisFilling = new class Chocolate_Fudge_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 3:
			thisFilling = new class Vanilla_Cream_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 4:
			thisFilling = new class Wild_Berry_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 5:
			thisFilling = new class Blueberry_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 6:
			thisFilling = new class Cherry_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 7:
			thisFilling = new class Raspberry_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 8:
			thisFilling = new class Strawberry_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 9:
			thisFilling = new class Peanut_Butter_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 10:
			thisFilling = new class Cookies_n_Cream_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 11:
			thisFilling = new class Cookie_dough_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 12:
			thisFilling = new class Vanilla_Icecream_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		case 13:
			thisFilling = new nutella_Filling; // make a new spread
			thisFilling->addToConsumables(thisPancake); // add pancake inside of spread - adding cost and description together
			thisPancake = thisFilling; //take encapsulated "pancake with spread" and allocate to main Pancake.

			thisFilling = NULL; // Clears our pointer for re-use, "thisPancake" handles clean up
			break;

		default:
			// An error message for user
			cout << "Your Selection is invalid" << "\n";
			break;
		}
	}

};


////////////////////////////////////////////
//-------State pattern begins here--------//
////////////////////////////////////////////

#pragma region "Classes - State pattern"

//Prototype: make dependant classes aware of the class existance.
class StateContext;

class Transition
{
public:
	// abstract interface, to be implemented in sub classes
	// is external to state.
	virtual void insertMoney(int) {}
	virtual void makeSelection(int, int, int){}
	virtual void moneyRejected(void){}
	virtual void addPancake(int number){}
	virtual void dispense(void){}

};

class State : public Transition
{
protected:

	StateContext* currentContext; // carries context compositionally, used to drive context specific actions in sub classes specific to context.

public:

	// on creation we need to set a state, constructor will achieve this.
	State(StateContext* Context)
	{
		currentContext = Context;
	}
};

// Lists states and Parameters, binds a text value to a numeric value e.g {cat, dog, fish, hamster, ...} {0,1,2,3,4, ...}.
enum state { Out_Of_Pancakes, No_Credit, Has_Credit, Dispenses_Pancakes };
enum stateParameter { No_Of_Pancakes, Credit, Cost_Of_Pancakes };

class StateContext
{
protected:

	State* currentState; // stores current state, drives context specific sub-classes
	vector<State*> availableStates; // stores a list of stats we can choose from, of type State.
	vector<int> stateParameters; // similar to available states, stores a list of int values, using state enum value as template for specific examples.
	resultPancake* PancakeHandler; // used to keep track of user constructed Pancake, allows the storing of created pancakes and the recollection of user selection.

public:
	~StateContext()
	{
		for (int i = 0; i < availableStates.size(); i++)
		{
			delete availableStates[i];
		}
		// for loop cleans all availableStates from memory.

		delete PancakeHandler; // clear Pancake from memory.
	}

	void setState(state newState)
	{
		this->currentState = availableStates[newState];
	}
	// get a available state with parameter of state specifically.

	void setStateParam(stateParameter SP, int value)
	{
		this->stateParameters[SP] = value;
	}
	// set a state param and then its value, holds label and the information along side it - eg cost of pancake, value of pancake in int.

	int getStateParam(stateParameter SP)
	{
		return this->stateParameters[SP];
	}
	// return a state parameter, allowing us to determine a value inside - eg. pancake mix quantity.


	void setActivePancake(resultPancake* Pancake)
	{
		this->PancakeHandler = Pancake;
	}
	// store a user selection pancake factory and the full pancake created.

	resultPancake* getPancake(){ return this->PancakeHandler; }
	// return/get a user selected pancake factory and the full pancake created.
	
};

// States
class OutOfPancakeMix : public State
{
public:

	OutOfPancakeMix(StateContext* Context) : State(Context){} // context value of state is same as state context value.

	// attempt to insert money
	void insertMoney(int money)
	{
		cout << "Error! No Pancakes left! Ejecting money!" << "\n";
	}

	// attempt to make selection
	void makeSelection(int Pancake_Option, int Topping_Option, int Filling_Option)
	{
		cout << "Error! No Pancakes left! No Selection Made!" << "\n";
	}

	// return money to user.
	void moneyRejected(void)
	{
		cout << "Ejecting credit!" << "\n"; //new transition added
	}

	// add pancake mix into machine for greater stock levels.
	void addPancake(int number)
	{
		this->currentContext->setStateParam(No_Of_Pancakes, number);
		this->currentContext->setState(No_Credit);
	}

	// attempt to dispense pancake, where no pancake mix is left in machine.
	void dispense(void)
	{
		cout << "Error! No Pancakes left! Nothing to Dispense!" << "\n";
	}

};

class NoCredit : public State
{
public:

	NoCredit(StateContext* Context) : State(Context){} // context value of state is same as state context value.

	// insert credit into machine, adding state has_credit
	void insertMoney(int money)
	{
		cout << "You inserted: " << money;
		this->currentContext->setStateParam(Credit, money);
		cout << " Total: " << money << "\n";
		this->currentContext->setState(Has_Credit);
	}

	// attempt to make selection, no credit makes this impossible.
	void makeSelection(int option)
	{
		cout << "Error! No Money!" << "\n";
	}

	// attempt to reclaim credit, no credit to reclaim.
	void moneyRejected(void)
	{
		cout << "Error! No Money!" << "\n";
	}

	// attempt to add pancake mix, cannot recieve more.
	void addPancake(int number)
	{
		cout << "Error! Already Got Pancake mix!" << "\n";
	}

	// attempt to dispense pancake, cannot due to lack of credit.
	void dispense(void)
	{
		cout << "Error! No Money!" << "\n";
	}

};

class HasCredit : public State
{
public:

	HasCredit(StateContext* Context) : State(Context){} // context value of state is same as state context value.

	// insert credit, credit updated. state updated.
	void insertMoney(int money)
	{
		cout << "You inserted: " << money;
		money = money + this->currentContext->getStateParam(Credit);
		this->currentContext->setStateParam(Credit, money);
		cout << " Total: " << money << "\n";
		this->currentContext->setState(Has_Credit);
	}

	// Make a selection with 3 int parameters that match enum lists
	// use resultPancake (pancake factory, with topping and filling options)
	// display result cost from Pancake factory "resultPancake".
	// set resultPancake class into current context for future reference.
	void makeSelection(int Pancake_Option, int Topping_Option, int Filling_Option)
	{
		resultPancake* PancakeHandler = new resultPancake(Pancake_Option);

		PancakeHandler->addSpread(Topping_Option);
		PancakeHandler->addFilling(Filling_Option);

		cout << "Selection made!" << "\n";
		cout << "Selection Costs: " << PancakeHandler->thisPancake->Cost() << "\n"; // user feedback

		this->currentContext->setActivePancake(PancakeHandler);
		this->currentContext->setState(Dispenses_Pancakes);
		this->currentContext->setStateParam(Cost_Of_Pancakes, PancakeHandler->thisPancake->Cost() ); // use our Pancake handler to return total costs to state machine.
	}

	// returns credit inserted.
	void moneyRejected(void)
	{
		cout << "Money Rejected!" << "\n";
		this->currentContext->setStateParam(Credit, 0);
		this->currentContext->setState(No_Credit);
	}

	// attempt to add more pancake mix, already full.
	void addPancake(int number)
	{
		cout << "Error! Already Got Pancake mix!" << "\n";
	}

	void dispense(void)
	{
		cout << "Error! No Selection Made!" << "\n";
	}

};

class DispensesPancake : public State
{
public:

	DispensesPancake(StateContext* Context) : State(Context){} // context value of state is same as state context value.

	// can't act due to dispensing process
	void insertMoney(int money)
	{
		cout << "Error! Busy Dispensing!" << "\n";
	}

	// can't act due to dispensing process
	void makeSelection(int Pancake_Option, int Topping_Option, int Filling_Option)
	{
		cout << "Error! Busy Dispensing!" << "\n";
	}

	// can't act due to dispensing process
	void moneyRejected(void)
	{
		cout << "Error! Busy Dispensing!" << "\n";
	}

	// can't act due to dispensing process
	void addPancake(int number)
	{
		cout << "Error! Busy Dispensing!" << "\n";
	}

	// check credit value
		// if credit greater than or equal to cost of the pancakes selected.
			// then dispense pancake, displaying the description from pancake decorator.
			// update state parameter of credit by reducing value of pancake value from credit.
			// Reduce total pancake mix by 1
		// else
			// output error not enough money.
	void dispense(void)
	{
		if (this->currentContext->getStateParam(Credit) >= this->currentContext->getStateParam(Cost_Of_Pancakes))
		{
			resultPancake* Pancake_Factory = this->currentContext->getPancake();
			cout << "Dispensing!" << "\n";
			Pancake_Factory->thisPancake->Description();
			cout << "\n\n";

			this->currentContext->setStateParam(Credit, this->currentContext->getStateParam(Credit) - this->currentContext->getStateParam(Cost_Of_Pancakes));
			this->currentContext->setStateParam(No_Of_Pancakes, this->currentContext->getStateParam(No_Of_Pancakes) - 1);

		}
		else
		{
			cout << "Error! Not enough money" << "\n";
		}

		// if credit is greater than 0 then set state to Has_Credit
		// else set to No_Credit
		if (this->currentContext->getStateParam(Credit) > 0)
		{
			this->currentContext->setState(Has_Credit);
		}
		else
		{
			this->currentContext->setState(No_Credit);
		}

		// check if Pancake mix is out/empty.
		// if true then set state to Out_Of_Pancakes
		if (this->currentContext->getStateParam(No_Of_Pancakes) == 0)
		{
			this->currentContext->setState(Out_Of_Pancakes);
		}
	}

};

//context
class Pancake_Dispenser : public StateContext, Transition
{

public:

	// constructor sets available states and state parameters.
	// use constructor parameter to declare pancake mix quanity.
	Pancake_Dispenser(int inventory_count)
	{
		this->availableStates.push_back(new OutOfPancakeMix(this));
		this->availableStates.push_back(new NoCredit(this));
		this->availableStates.push_back(new HasCredit(this));
		this->availableStates.push_back(new DispensesPancake(this));
		this->stateParameters.push_back(0); // No of Pancakes
		this->stateParameters.push_back(0); // Available Credit
		this->stateParameters.push_back(50); //Cost of Pancake Bar

		this->setState(Out_Of_Pancakes);
		if (inventory_count > 0)
		{
			this->addPancake(inventory_count);
		}

	}

	// insert money to state.
	void insertMoney(int money)
	{
		this->currentState->insertMoney(money);
	}

	// pancake selection function, 3 parameters: base pancake, toppings and then fillings.
	void makeSelection(int Pancake_Option, int Topping_Option, int Filling_Option)
	{
		this->currentState->makeSelection(Pancake_Option, Topping_Option, Filling_Option);
	}

	// set state to return credit inserted.
	void moneyRejected(void)
	{
		this->currentState->moneyRejected();
	}

	// added Pancake mix by number in parameter, updating the state.
	void addPancake(int number)
	{
		this->currentState->addPancake(number);
	}

	// set dispense state.
	void dispense(void)
	{
		this->currentState->dispense();
	}


};


#pragma endregion

////////////////////////////////////////////
//---------State pattern ends here--------//
////////////////////////////////////////////

// Main

void main()
{
	// Example selections. {0, 1, 2, 3, 4, ...}
		// ListPancakes { Normal_Pancake, Lemon_Pancake, Chocolate_Pancake };
		// ListSpreads { Frosted, Wildlicious, Chocolate, Smarties, Hundreds_Thous, Jelly_beans, Wild_Berry, Brown_Sugar, Chocolate_Chip, Maple_Syrup, Nutella_Spread };
		// ListFillings { Chocolate, Fudge, Chocolate_Fudge, Vanilla_Cream, Wild_Berry, Blueberry, Cherry, Raspberry, Strawberry, Peanut_Butter, Cookies_n_Cream, Cookie_dough, Vanilla_Icecream, Nutella_Filling };
	// function Makeselection("base pancake", "spread", "filling")

	Pancake_Dispenser* myDispenser = new Pancake_Dispenser(2);

	myDispenser->insertMoney(50);
	myDispenser->makeSelection(Lemon_Pancake, Frosted, Vanilla_Icecream);
	myDispenser->dispense();

	myDispenser->makeSelection(Normal_Pancake, Smarties, Nutella_Filling); //should display error message
	myDispenser->insertMoney(50);
	myDispenser->makeSelection(Chocolate_Pancake, Maple_Syrup, Nutella_Filling);
	myDispenser->dispense(); //No more Pancake

	myDispenser->insertMoney(50); //should display error message
	myDispenser->makeSelection(0, 2, 0); //should display error message
	myDispenser->dispense();//should display error message
	myDispenser->moneyRejected(); //should still work

	delete myDispenser;


	// freezes program at run time (debugging purposes).
	cin.get();
}


//Template Example
/*
Class Example:
Although there is no clear example of a template pattern, the principle involves an abstract class that defines
a method that calls a process of multiple preperation methods from the same class.

These methods vary on concrete sub-classes which then use the same preperation method, but activate various preperation methods as required.
e.g

// CODE:

class SandwichClubs
{
public:
	int wantsMeat = 1, wantsVeg = 1, wantsFruit = 1, isToasted = 1; 
	// Hooks, these allow methods to change behaviour in sub-classes through prepare method.

	SandwichClubs()
	{ PrepareSandwich(); }

	~SandwichClubs()

	virtual void addBread(){}
	virtual void addMeat(){}
	virtual void addVeg(){}
	virtual void addFruit(){}
	virtual void Toast(){}
	virtual void Serve(){}

	void PrepareSandwich()
	{
		addBread()
		addMeat()
		addVeg()
		addFruit()
		Toast()
		Serve()
	}

}

class ToastedVegetarian : SandwichClubs
{
public:
	ToastedVegetarian()
	{

		int wantsMeat = 0;

		~ToastedVegetarian()

		 void addBread(){ cout << "adding bread" << "\n";}
		 void addMeat(){ if(wantsMeat == 1) {cout << "adding meat." << "\n"; }	}
		 void addVeg(){ if(wantsVeg == 1) {cout << "adding Vegetables." << "\n"; }}
		 void addFruit(){ if(wantsFruit == 1) {cout << "adding Fruit." << "\n"; }}
		 void Toast(){ if(isToasted == 1) {cout << "toasting sandwich." << "\n"; }}
		 void Serve(){cout << "Serving." << "\n";}

		void PrepareSandwich()
			{
				addBread()
				addMeat()
				addVeg()
				addFruit()
				Toast()
				Serve()
		}
}

class BlackHamSandwich : SandwichClubs
{
public:
	ToastedVegetarian()
	{
	~ToastedVegetarian()

	void addBread(){ cout << "adding bread" << "\n";}
	void addMeat(){ if(wantsMeat == 1) {cout << "adding meat." << "\n"; }	}
	void addVeg(){ if(wantsVeg == 1) {cout << "adding Vegetables." << "\n"; }}
	void addFruit(){ if(wantsFruit == 1) {cout << "adding Fruit." << "\n"; }}
	void Toast(){ if(isToasted == 1) {cout << "toasting sandwich." << "\n"; }}
	void Serve(){cout << "Serving." << "\n";}

	void PrepareSandwich()
		{
			addBread()
			addMeat()
			addVeg()
			addFruit()
			Toast()
			Serve()
		}
}

*/