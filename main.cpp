/*
Author: Aaron Batch
Date: Tues, Dec. 1, 2015
Decription of Program: This is the Smallsville Library Management System V2, which is a fairly large library management computer program which does things like 
stores accounts of patrons (people who use the library) books, and the rentals that relate the two. These accounts hold data, and are organized is such a way
to make it relatively easy and simple to traverse.

*UPDATE*
The program can now store other items such as DVDs, Audiobooks, and Reference books. 

*DISCLAIMER*: Though this program is fairly large, there are some things still not functional in it yet. At the moment, the patron's names are not alphabetized. 
Also there is currently no saving feature in this program, meaning that once the program ends, all of the data is lost. Additionally, the fine rate system is very simple. You can add money onto a
persons fine amount, and change their fine rate depending on how long they have lost the book for. However, the program does not use any time functions at the moment, sothe fine amount for a patron 
will not update everytime you open the program (meaning that the weekly fine rate attribute in the "Patrons" class, does not function at the moment, it just tells what the weekly fine rate is supposed 
to be. However, you can still use the fine amount attribute in the "Patrons" class to manually add money to the patron's account. Also, try to keep all data typed as accurate to the instructions 
as possible, as to avoid any unforseen or hidden bugs that may still lie in the program. 
*/
#include "header_file.h"
void save_and_exit();

//Declare class that will serve as the parent class for all of the items in the library system
class Items
{
	public:
	//virtual void add_book(Books book);
//        virtual void remove_book() = 0;
//      virtual void edit_info_1book() = 0;
//        virtual void print_info_1book() = 0;
//        virtual void print_overdue_books() = 0;

	//virtual void add_DVD(DVDs dvd);
	//virtual void add_aud_book(Audio_Books audio_book);

	virtual void remove_item() = 0;
	virtual void edit_info_1item() = 0;
	virtual void print_info_1item() = 0;
	virtual void print_overdue_items() = 0;
	virtual void print_all_items() = 0;
};

//Declare class that will serve as the "books" class of the library system
class Books : public Items
{
        public:
        void add_book(Books book);
        void remove_book();
        void edit_info_1book();
        void print_info_1book();
        void print_overdue_books();
	void print_all_books();

	void remove_item();
	void edit_info_1item();
	void print_info_1item();
	void print_overdue_items();
	void print_all_items();

	private:
        string name_of_book;
        string author_of_book;
        int aq_num;
        int status;
	vector<Books> book_vec;

        public:
        Books();
};
//Dummy Functions
void Books :: remove_item()
{
        cout << "poop" << endl;
}

void Books :: edit_info_1item()
{
        cout << "poop" << endl;
}

void Books :: print_info_1item()
{
        cout << "poop" << endl;
}

void Books :: print_overdue_items()
{
        cout << "poop" << endl;
}

void Books :: print_all_items()
{
        cout << "poop" << endl;
}


//This function will add books to the registry
void Books :: add_book(Books book)
{
	char name[20];
        bool match = false;
        int i = 0, j = 0;
        int a, b;
	int response;

        book_vec.push_back(book);
        vector<Books>::iterator book_it = book_vec.begin();

        cout << "Please Enter Name Of Book: ";
        //cin >> book_vec[book_vec.size() - 1].name_of_book;
        cin.ignore();
        getline(cin, book_vec[book_vec.size() - 1].name_of_book);
        cout << endl;
	cout << book_vec[book_vec.size() - 1].name_of_book << endl;

        cout << "Please Enter Acquisition Number Of Book: ";
        cin >> book_vec[book_vec.size() - 1].aq_num;
        cout << endl;
	cout << book_vec[book_vec.size() - 1].aq_num << endl;

        cout << "Please Enter Author Of Book: ";
        cin.ignore();
        getline(cin, book_vec[book_vec.size() - 1].author_of_book);
        //cin >> book_vec[book_vec.size() - 1].author_of_book;
        cout << endl;
	cout << book_vec[book_vec.size() - 1].author_of_book << endl;

	cout << "Please Enter Status Of Book:" << endl;
	cout << "Press 1 for: Returned Or Currently In Library" << endl;
	cout << "Press 2 for: Rented By A Patron" << endl;
	cout << "Press 3 for: Overdue" << endl;
	cout << "Press 4 for: Lost Or Destroyed" << endl;
	cout << "Press 5 for: Removed From Library" << endl;

	cout << "Response: ";
	cin >> response;

	switch (response)
	{
		case 1:
			book_vec[book_vec.size() - 1].status = response;
			break;

		case 2:
			book_vec[book_vec.size() - 1].status = response;
			break;

		case 3:
			book_vec[book_vec.size() - 1].status = response;
			break;

		case 4:
			book_vec[book_vec.size() - 1].status = response;
			break;

		case 5:
			book_vec[book_vec.size() - 1].status = response;
			break;

		default:
			break;
	}
        cout << endl;
	cout << book_vec[book_vec.size() - 1].status << endl;

};

//This function will remove books from the registry
void Books :: remove_book()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];

        cout << "Please Enter The Acquisition Number Of The Book That You Would Like To Remove From The System: ";
        cin >> AQ_Num;

        for(i = 0; i < book_vec.size(); i++)
        {
                if(book_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        book_vec.erase(book_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }


};

//This function will let you edit the information on one book
void Books :: edit_info_1book()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];
	int response;

        cout << "Please Enter The Acquisition Number Of The Book That You Would Like To Edit: ";
        cin >> AQ_Num;

        for(i = 0; i < book_vec.size(); i++)
        {
                if(book_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

	do
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
                cout << "|            Welcome To The Book  Account Editing Interface!               |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                         What Would You Like To Do?                       |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|  1. Edit Books's Name                                                    |" << endl;
                cout << "|  2. Edit Book's Author                                                   |" << endl;
                cout << "|  3. Edit Book's Acquisition Number                                       |" << endl;
                cout << "|  4. Edit Book's Status                                                   |" << endl;
                cout << "|  5. Exit Menu                                                            |" << endl;
                cout << "*--------------------------------------------------------------------------*" << endl;

                cout << "Response: ";
                cin >> response;

		switch (response)
		{
			case 1:
				cout << "Please Enter The Book's Name: ";
				cin.ignore();
                                getline(cin, book_vec[location].name_of_book);
                                //cout << book_vec[location].name_of_book << endl;
                                cout << endl;
                                break;

			case 2:
				cout << "Pleae Enter The Book's Author: ";
				cin.ignore();
				getline(cin, book_vec[location].author_of_book);
				//cout << book_vec[location].author_of_book << endl;
				cout << endl;
				break;

			case 3:
				cout << "Pleae Enter the Book's Acquisition Number: ";
				cin >> book_vec[location].aq_num;
				//cout << book_vec[location].aq_num << endl;
				cout << endl;
				break;

			case 4:
				cout << "Please Enter Status Of Book:" << endl;
        			cout << "Press 1 for: Returned Or Currently In Library" << endl;
        			cout << "Press 2 for: Rented By A Patron" << endl;
        			cout << "Press 3 for: Overdue" << endl;
        			cout << "Press 4 for: Lost Or Destroyed" << endl;
        			cout << "Press 5 for: Removed From Library" << endl;

				cin >> book_vec[location].status;

				//cout << book_vec[location].status << endl;

			case 5:
				break;
		}


	}while(response != 5);


};

//This function will print all of the information on one user defined book
void Books :: print_info_1book()
{
	int i = 0, j, location;
        int AQ_Num;
        int response = 0;

        cout << "Please Enter Acquisition Number Of The Book Whose Account Information You Would Like To See: ";
        cin >> AQ_Num;

        for(i = 0; i < book_vec.size(); i++)
        {
                if(book_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

                cout << "Book Information: "<< endl;
                cout << endl;
                cout << "1. Book Name: " << setw(4) << left << book_vec[location].name_of_book << endl;
                cout << "2. Book Author Name: " << setw(4) << left << book_vec[location].author_of_book << endl;
                cout << "3. Book Acquisition Number: " << setw(4) << left << book_vec[location].aq_num << endl;

		if(book_vec[location].status == 1)
		{
			cout << "4. Book Status: Returned Of Currently In Library" << endl;
		}

		if(book_vec[location].status == 2)
		{
			cout << "4. Book Status: Rented By A Patron" << endl;
		}

		if(book_vec[location].status == 3)
		{
			cout << "4. Book Status: Overdue" << endl;
		}

		if(book_vec[location].status == 4)
		{
			cout << "4. Book Status: Lost Or Destroyed" << endl;
		}

		if(book_vec[location].status == 5)
		{
			cout << "4. Book Status: Removed From Library" << endl;
		}

                cout << endl;

};

//This function will print all overdue books that are currently in the system
void Books :: print_overdue_books()
{
	int i, j;
        int counter = 1;

        cout << "List Of Books That Are Overdue: " << endl;

        for(i = 0; i < book_vec.size(); i++)
        {
                if(book_vec[i].status == 3)
                {
                        cout << "Book: " << counter << endl;
                        cout << "1. Book Name: " << setw(4) << left << book_vec[i].name_of_book << endl;
                        cout << "2. Book Author: " << setw(4) << left << book_vec[i].author_of_book << endl;
                        cout << "3. Book Acquisition Number: " << setw(4) << left << book_vec[i].aq_num << endl;

                        counter++;
                        cout << endl;
                }
        }

};

//This function prints all books in the registry
void Books :: print_all_books()
{
	int i, j;
        int counter = 1;

        cout << "List Of Books: " << endl;

        for(i = 0; i < book_vec.size(); i++)
        {
        	cout << "Book: " << counter << endl;
                cout << "1. Book Name: " << setw(4) << left << book_vec[i].name_of_book << endl;
                cout << "2. Book Author: " << setw(4) << left << book_vec[i].author_of_book << endl;
                cout << "3. Book Acquisition Number: " << setw(4) << left << book_vec[i].aq_num << endl;

                counter++;
                cout << endl;
        }

}

//This is the default constructor for the books class
Books :: Books()
{
	status = 1;
};

//This class will act as the class that will house all of the information pertaining to DVDs
class DVDs : public Items
{
        public:
        void add_DVD(DVDs dvds);
        void remove_item();
        void edit_info_1item();
        void print_info_1item();
        void print_overdue_items();
	void print_all_items();

        private:
        string name_of_DVD;
        int aq_num;
        int status;
        vector<DVDs> dvd_vec;

        public:
        DVDs();
};
//This function adds DVDs into the system
void DVDs :: add_DVD(DVDs dvds)
{
	char name[20];
        bool match = false;
        int i = 0, j = 0;
        int a, b;
        int response;

        dvd_vec.push_back(dvds);
        vector<DVDs>::iterator DVD_it = dvd_vec.begin();

        cout << "Please Enter Name Of DVD: ";
        //cin >> dvd_vec[dvd_vec.size() - 1].name_of_DVD;
        cin.ignore();
        getline(cin, dvd_vec[dvd_vec.size() - 1].name_of_DVD);
        cout << endl;
        cout << dvd_vec[dvd_vec.size() - 1].name_of_DVD << endl;

        cout << "Please Enter Acquisition Number Of DVD: ";
        cin >> dvd_vec[dvd_vec.size() - 1].aq_num;
        cout << endl;
        cout << dvd_vec[dvd_vec.size() - 1].aq_num << endl;

        cout << "Please Enter Status Of DVD:" << endl;
        cout << "Press 1 for: Returned Or Currently In Library" << endl;
        cout << "Press 2 for: Rented By A Patron" << endl;
        cout << "Press 3 for: Overdue" << endl;
        cout << "Press 4 for: Lost Or Destroyed" << endl;
        cout << "Press 5 for: Removed From Library" << endl;

        cout << "Response: ";
        cin >> response;

	switch (response)
        {
                case 1:
                        dvd_vec[dvd_vec.size() - 1].status = response;
                        break;

                case 2:
                        dvd_vec[dvd_vec.size() - 1].status = response;
                        break;

                case 3:
                        dvd_vec[dvd_vec.size() - 1].status = response;
                        break;

                case 4:
                        dvd_vec[dvd_vec.size() - 1].status = response;
                        break;

                case 5:
                        dvd_vec[dvd_vec.size() - 1].status = response;
                        break;

                default:
                        break;
        }

	cout << endl;
        cout << dvd_vec[dvd_vec.size() - 1].status << endl;
}
//This function removes dvds from the system
void DVDs :: remove_item()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];

        cout << "Please Enter The Acquisition Number Of The DVD That You Would Like To Remove From The System: ";
        cin >> AQ_Num;

        for(i = 0; i < dvd_vec.size(); i++)
        {
                if(dvd_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        dvd_vec.erase(dvd_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

}
//This function lets the user edit the info on a dvd
void DVDs :: edit_info_1item()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];
        int response;

        cout << "Please Enter The Acquisition Number Of The DVD That You Would Like To Edit: ";
        cin >> AQ_Num;

        for(i = 0; i < dvd_vec.size(); i++)
        {
                if(dvd_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

	do
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
                cout << "|            Welcome To The DVD Account Editing Interface!                 |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                         What Would You Like To Do?                       |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|  1. Edit DVD's Name                                                      |" << endl;
                cout << "|  2. Edit DVD's Acquisition Number                                        |" << endl;
                cout << "|  3. Edit DVD's Status                                                    |" << endl;
                cout << "|  4. Exit Menu                                                            |" << endl;
                cout << "*--------------------------------------------------------------------------*" << endl;

                cout << "Response: ";
                cin >> response;

		switch (response)
		{
			case 1:
                                cout << "Please Enter The DVD's Name: ";
                                cin.ignore();
                                getline(cin, dvd_vec[location].name_of_DVD);
                                //cout << dvd_vec[location].name_of_DVD << endl;
                                cout << endl;
                                break;

                        case 2:
                                cout << "Pleae Enter the DVD's Acquisition Number: ";
                                cin >> dvd_vec[location].aq_num;
                                //cout << dvd_vec[location].aq_num << endl;
                                cout << endl;
                                break;

                        case 3:
                                cout << "Please Enter Status Of DVD:" << endl;
                                cout << "Press 1 for: Returned Or Currently In Library" << endl;
                                cout << "Press 2 for: Rented By A Patron" << endl;
                                cout << "Press 3 for: Overdue" << endl;
                                cout << "Press 4 for: Lost Or Destroyed" << endl;
                                cout << "Press 5 for: Removed From Library" << endl;

                                cin >> dvd_vec[location].status;

                                //cout << dvd_vec[location].status << endl;

                        case 4:
                                break;

		}


	}while (response != 4);

}
//This function lets the user print all of the info on one dvd
void DVDs :: print_info_1item()
{
	int i = 0, j, location;
        int AQ_Num;
        int response = 0;

        cout << "Please Enter Acquisition Number Of The DVD Whose Account Information You Would Like To See: ";
        cin >> AQ_Num;

        for(i = 0; i < dvd_vec.size(); i++)
        {
                if(dvd_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

                cout << "DVD Information: "<< endl;
                cout << endl;
                cout << "1. DVD Name: " << setw(4) << left << dvd_vec[location].name_of_DVD << endl;
                cout << "2. DVD Acquisition Number: " << setw(4) << left << dvd_vec[location].aq_num << endl;

                if(dvd_vec[location].status == 1)
                {
                        cout << "3. DVD Status: Returned Of Currently In Library" << endl;
                }

                if(dvd_vec[location].status == 2)
                {
                        cout << "3. DVD Status: Rented By A Patron" << endl;
                }

                if(dvd_vec[location].status == 3)
                {
                        cout << "3. DVD Status: Overdue" << endl;
                }

                if(dvd_vec[location].status == 4)
                {
                        cout << "3. DVD Status: Lost Or Destroyed" << endl;
                }

		if(dvd_vec[location].status == 5)
                {
                        cout << "3. DVD Status: Removed From Library" << endl;
                }

                cout << endl;

}
//This function allows the user to print a list of all overdue dvds
void DVDs :: print_overdue_items()
{
	int i, j;
        int counter = 1;

        cout << "List Of DVDs That Are Overdue: " << endl;

        for(i = 0; i < dvd_vec.size(); i++)
        {
                if(dvd_vec[i].status == 3)
                {
                        cout << "DVD: " << counter << endl;
                        cout << "1. DVD Name: " << setw(4) << left << dvd_vec[i].name_of_DVD << endl;
                        cout << "2. DVD Acquisition Number: " << setw(4) << left << dvd_vec[i].aq_num << endl;

                        counter++;
                        cout << endl;
                }
        }

}
//This function allows the user to print off a list of all dvds
void DVDs :: print_all_items()
{
	int i, j;
        int counter = 1;

        cout << "List Of DVDs: " << endl;

        for(i = 0; i < dvd_vec.size(); i++)
        {
                cout << "DVD: " << counter << endl;
                cout << "1. DVD Name: " << setw(4) << left << dvd_vec[i].name_of_DVD << endl;
                cout << "2. DVD Acquisition Number: " << setw(4) << left << dvd_vec[i].aq_num << endl;

                counter++;
                cout << endl;
        }
}
//This function acts as the constructor for this class
DVDs :: DVDs()
{
	status = 1;
}

//This class will act as the class that will house all of the information pertaining to Audiobooks
class Audio_Books : public Items
{
        public:
        void add_aud_book(Audio_Books audio_books);
        void remove_item();
        void edit_info_1item();
        void print_info_1item();
        void print_overdue_items();
        void print_all_items();

        private:
        string name_of_aud_book;
	string author_of_aud_book;
        int aq_num;
        int status;
        vector<Audio_Books> aud_book_vec;

        public:
        Audio_Books();
}; 
//This function adds audiobooks to the system
void Audio_Books :: add_aud_book(Audio_Books audio_books)
{
	char name[20];
        bool match = false;
        int i = 0, j = 0;
        int a, b;
        int response;

        aud_book_vec.push_back(audio_books);
        vector<Audio_Books>::iterator aud_book_it = aud_book_vec.begin();

        cout << "Please Enter Name Of Audiobook: ";
        //cin >> aud_book_vec[aud_book_vec.size() - 1].name_of_aud_book;
        cin.ignore();
        getline(cin, aud_book_vec[aud_book_vec.size() - 1].name_of_aud_book);
        cout << endl;
        cout << aud_book_vec[aud_book_vec.size() - 1].name_of_aud_book << endl;

        cout << "Please Enter Acquisition Number Of Audiobook: ";
        cin >> aud_book_vec[aud_book_vec.size() - 1].aq_num;
        cout << endl;
        cout << aud_book_vec[aud_book_vec.size() - 1].aq_num << endl;

	cout << "Please Enter Author Of Audiobook: ";
        cin.ignore();
        getline(cin, aud_book_vec[aud_book_vec.size() - 1].author_of_aud_book);
        //cin >> aud_book_vec[aud_book_vec.size() - 1].author_of_aud_book;
        cout << endl;
        cout << aud_book_vec[aud_book_vec.size() - 1].author_of_aud_book << endl;

        cout << "Please Enter Status Of Audiobook:" << endl;
        cout << "Press 1 for: Returned Or Currently In Library" << endl;
        cout << "Press 2 for: Rented By A Patron" << endl;
        cout << "Press 3 for: Overdue" << endl;
        cout << "Press 4 for: Lost Or Destroyed" << endl;
        cout << "Press 5 for: Removed From Library" << endl;

        cout << "Response: ";
        cin >> response;

	switch (response)
        {
                case 1:
                        aud_book_vec[aud_book_vec.size() - 1].status = response;
                        break;

                case 2:
                        aud_book_vec[aud_book_vec.size() - 1].status = response;
                        break;

                case 3:
                        aud_book_vec[aud_book_vec.size() - 1].status = response;
                        break;

                case 4:
                        aud_book_vec[aud_book_vec.size() - 1].status = response;
                        break;

                case 5:
                        aud_book_vec[aud_book_vec.size() - 1].status = response;
                        break;

                default:
                        break;
        }

        cout << endl;
        cout << aud_book_vec[aud_book_vec.size() - 1].status << endl;
}
//This function removes audiobooks from the system
void Audio_Books :: remove_item()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];

        cout << "Please Enter The Acquisition Number Of The Audiobook That You Would Like To Remove From The System: ";
        cin >> AQ_Num;

        for(i = 0; i < aud_book_vec.size(); i++)
        {
                if(aud_book_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        aud_book_vec.erase(aud_book_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

}
//This function lets the user edit the info of one audiobook
void Audio_Books :: edit_info_1item()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];
        int response;

        cout << "Please Enter The Acquisition Number Of The Audiobook That You Would Like To Edit: ";
        cin >> AQ_Num;

        for(i = 0; i < aud_book_vec.size(); i++)
        {
                if(aud_book_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

	do
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
                cout << "|            Welcome To The Audiobook Account Editing Interface!           |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                         What Would You Like To Do?                       |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|  1. Edit Audiobook's Name                                                |" << endl;
		cout << "|  2. Edit Audiobook's Author                                              |" << endl;
                cout << "|  3. Edit Audiobook's Acquisition Number                                  |" << endl;
                cout << "|  4. Edit Audiobooks's Status                                             |" << endl;
                cout << "|  5. Exit Menu                                                            |" << endl;
                cout << "*--------------------------------------------------------------------------*" << endl;

                cout << "Response: ";
                cin >> response;

		switch (response)
                {
                        case 1:
                                cout << "Please Enter The Audiobook's Name: ";
                                cin.ignore();
                                getline(cin, aud_book_vec[location].name_of_aud_book);
                                //cout << aud_book_vec[location].name_of_aud_book << endl;
                                cout << endl;
                                break;

			case 2:
                                cout << "Pleae Enter The Audiobook's Author: ";
                                cin.ignore();
                                getline(cin, aud_book_vec[location].author_of_aud_book);
                                //cout << aud_book_vec[location].author_of_aud_book << endl;
                                cout << endl;
                                break;


                        case 3:
                                cout << "Pleae Enter the Audiobook's Acquisition Number: ";
                                cin >> aud_book_vec[location].aq_num;
                                //cout << aud_book_vec[location].aq_num << endl;
                                cout << endl;
                                break;

                        case 4:
                                cout << "Please Enter Status Of Audiobook:" << endl;
                                cout << "Press 1 for: Returned Or Currently In Library" << endl;
                                cout << "Press 2 for: Rented By A Patron" << endl;
                                cout << "Press 3 for: Overdue" << endl;
                                cout << "Press 4 for: Lost Or Destroyed" << endl;
                                cout << "Press 5 for: Removed From Library" << endl;

                                cin >> aud_book_vec[location].status;

                                //cout << aud_book_vec[location].status << endl;

                        case 5:
                                break;

			default:
				break;

                }


	}while (response != 5);

}

//This funtion loets the user print the info on one audiobook
void Audio_Books :: print_info_1item()
{
	int i = 0, j, location;
        int AQ_Num;
        int response = 0;

        cout << "Please Enter Acquisition Number Of The Audiobook Whose Account Information You Would Like To See: ";
        cin >> AQ_Num;

        for(i = 0; i < aud_book_vec.size(); i++)
        {
                if(aud_book_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

                cout << "Audiobook Information: "<< endl;
                cout << endl;
                cout << "1. Audiobook Name: " << setw(4) << left << aud_book_vec[location].name_of_aud_book << endl;
		cout << "2. Audiobook Author Name: " << setw(4) << left << aud_book_vec[location].author_of_aud_book << endl;
                cout << "3. Audiobook Acquisition Number: " << setw(4) << left << aud_book_vec[location].aq_num << endl;

		 if(aud_book_vec[location].status == 1)
                {
                        cout << "4. Audiobook Status: Returned Of Currently In Library" << endl;
                }

                if(aud_book_vec[location].status == 2)
                {
                        cout << "4. Audiobook Status: Rented By A Patron" << endl;
                }

                if(aud_book_vec[location].status == 3)
                {
                        cout << "4. Audiobook Status: Overdue" << endl;
                }

                if(aud_book_vec[location].status == 4)
                {
                        cout << "4. Audiobook Status: Lost Or Destroyed" << endl;
                }

                if(aud_book_vec[location].status == 5)
                {
                        cout << "4. Audiobook Status: Removed From Library" << endl;
                }

                cout << endl;

}
//This function lets the user print a list of all overdue audiobooks
void Audio_Books :: print_overdue_items()
{
	int i, j;
        int counter = 1;

        cout << "List Of Audiobooks That Are Overdue: " << endl;

        for(i = 0; i < aud_book_vec.size(); i++)
        {
                if(aud_book_vec[i].status == 3)
                {
                        cout << "Audiobook: " << counter << endl;
                        cout << "1. Audiobook Name: " << setw(4) << left << aud_book_vec[i].name_of_aud_book << endl;
                        cout << "2. Audiobook Author: " << setw(4) << left << aud_book_vec[i].author_of_aud_book << endl;
                        cout << "3. Audiobook Acquisition Number: " << setw(4) << left << aud_book_vec[i].aq_num << endl;

                        counter++;
                        cout << endl;
                }
        }

}
//This function prints off a list of all audiobooks
void Audio_Books :: print_all_items()
{
	int i, j;
        int counter = 1;

        cout << "List Of Audiobooks: " << endl;

        for(i = 0; i < aud_book_vec.size(); i++)
        {
                cout << "Audiobook: " << counter << endl;
                cout << "1. Audiobook Name: " << setw(4) << left << aud_book_vec[i].name_of_aud_book << endl;
                cout << "2. Audiobook Author: " << setw(4) << left << aud_book_vec[i].author_of_aud_book << endl;
                cout << "3. Audiobook Acquisition Number: " << setw(4) << left << aud_book_vec[i].aq_num << endl;

                counter++;
                cout << endl;
        }

}
//This function acta as the constructor for this class
Audio_Books :: Audio_Books()
{
        status = 1;
}
//This class will act as the class that will house all of the information pertaining to References
class References : public Items
{
        public:
        void add_ref(References references);
        void remove_item();
        void edit_info_1item();
        void print_info_1item();
        void print_overdue_items();
        void print_all_items();

        private:
        string name_of_ref;
	string author_of_ref;
        int aq_num;
        int status;
        vector<References> ref_vec;

        public:
        References();
};
//This function adds references to the system
void References :: add_ref(References references)
{
	char name[20];
        bool match = false;
        int i = 0, j = 0;
        int a, b;
        int response;

        ref_vec.push_back(references);
        vector<References>::iterator ref_it = ref_vec.begin();

        cout << "Please Enter Name Of The Reference: ";
        //cin >> ref_vec[ref_vec.size() - 1].name_of_ref;
        cin.ignore();
        getline(cin, ref_vec[ref_vec.size() - 1].name_of_ref);
        cout << endl;
        cout << ref_vec[ref_vec.size() - 1].name_of_ref << endl;

        cout << "Please Enter Acquisition Number Of Reference: ";
        cin >> ref_vec[ref_vec.size() - 1].aq_num;
        cout << endl;
        cout << ref_vec[ref_vec.size() - 1].aq_num << endl;

        cout << "Please Enter Author Of Reference: ";
        cin.ignore();
        getline(cin, ref_vec[ref_vec.size() - 1].author_of_ref);
        //cin >> ref_vec[ref_vec.size() - 1].author_of_ref;
        cout << endl;
        cout << ref_vec[ref_vec.size() - 1].author_of_ref << endl;

	cout << "Please Enter Status Of Reference:" << endl;
        cout << "Press 1 for: Returned Or Currently In Library" << endl;
        cout << "Press 2 for: Rented By A Patron" << endl;
        cout << "Press 3 for: Overdue" << endl;
        cout << "Press 4 for: Lost Or Destroyed" << endl;
        cout << "Press 5 for: Removed From Library" << endl;

        cout << "Response: ";
        cin >> response;

        switch (response)
        {
                case 1:
                        ref_vec[ref_vec.size() - 1].status = response;
                        break;

                case 2:
                        ref_vec[ref_vec.size() - 1].status = response;
                        break;

                case 3:
                        ref_vec[ref_vec.size() - 1].status = response;
                        break;

                case 4:
                        ref_vec[ref_vec.size() - 1].status = response;
                        break;

                case 5:
                        ref_vec[ref_vec.size() - 1].status = response;
                        break;

                default:
                        break;
        }

        cout << endl;
        cout << ref_vec[ref_vec.size() - 1].status << endl;

}
//This function removes references from the system
void References :: remove_item()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];

        cout << "Please Enter The Acquisition Number Of The Reference That You Would Like To Remove From The System: ";
        cin >> AQ_Num;

        for(i = 0; i < ref_vec.size(); i++)
        {
                if(ref_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        ref_vec.erase(ref_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

}
//This function lets the user edit the info on 1 reference
void References :: edit_info_1item()
{
	int i = 0, j, location;
        int AQ_Num;
        char words[20];
        int response;

        cout << "Please Enter The Acquisition Number Of The Reference That You Would Like To Edit: ";
        cin >> AQ_Num;

        for(i = 0; i < ref_vec.size(); i++)
        {
                if(ref_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

	do
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
                cout << "|            Welcome To The Reference Account Editing Interface!           |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                         What Would You Like To Do?                       |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|  1. Edit Reference's Name                                                |" << endl;
                cout << "|  2. Edit Reference's Author                                              |" << endl;
                cout << "|  3. Edit Reference's Acquisition Number                                  |" << endl;
                cout << "|  4. Edit Reference's Status                                              |" << endl;
                cout << "|  5. Exit Menu                                                            |" << endl;
                cout << "*--------------------------------------------------------------------------*" << endl;

                cout << "Response: ";
                cin >> response;

		switch (response)
		{
			case 1:
                                cout << "Please Enter The Reference's Name: ";
                                cin.ignore();
                                getline(cin, ref_vec[location].name_of_ref);
                                //cout << ref_vec[location].name_of_ref << endl;
                                cout << endl;
                                break;

                        case 2:
                                cout << "Pleae Enter The Reference's Author: ";
                                cin.ignore();
                                getline(cin, ref_vec[location].author_of_ref);
                                //cout << ref_vec[location].author_of_ref << endl;
                                cout << endl;
                                break;

                        case 3:
                                cout << "Pleae Enter the Reference's Acquisition Number: ";
                                cin >> ref_vec[location].aq_num;
                                //cout << ref_vec[location].aq_num << endl;
                                cout << endl;
                                break;

			case 4:
                                cout << "Please Enter Status Of The Reference:" << endl;
                                cout << "Press 1 for: Returned Or Currently In Library" << endl;
                                cout << "Press 2 for: Rented By A Patron" << endl;
                                cout << "Press 3 for: Overdue" << endl;
                                cout << "Press 4 for: Lost Or Destroyed" << endl;
                                cout << "Press 5 for: Removed From Library" << endl;

                                cin >> ref_vec[location].status;

                                //cout << ref_vec[location].status << endl;

                        case 5:
                                break;



		}

	}while(response != 5);

}
//This function lets the suer print off all of the info on one reference
void References :: print_info_1item()
{
	int i = 0, j, location;
        int AQ_Num;
        int response = 0;

        cout << "Please Enter Acquisition Number Of The Reference Whose Account Information You Would Like To See: ";
        cin >> AQ_Num;

        for(i = 0; i < ref_vec.size(); i++)
        {
                if(ref_vec[i].aq_num == AQ_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

                cout << "Reference Information: "<< endl;
                cout << endl;
                cout << "1. Reference Name: " << setw(4) << left << ref_vec[location].name_of_ref << endl;
                cout << "2. Reference Author Name: " << setw(4) << left << ref_vec[location].author_of_ref << endl;
                cout << "3. Reference Acquisition Number: " << setw(4) << left << ref_vec[location].aq_num << endl;

                if(ref_vec[location].status == 1)
                {
                        cout << "4. Reference Status: Returned Of Currently In Library" << endl;
                }

                if(ref_vec[location].status == 2)
                {
                        cout << "4. Reference Status: Rented By A Patron" << endl;
                }

		if(ref_vec[location].status == 3)
                {
                        cout << "4. Reference Status: Overdue" << endl;
                }

                if(ref_vec[location].status == 4)
                {
                        cout << "4. Reference Status: Lost Or Destroyed" << endl;
                }

                if(ref_vec[location].status == 5)
                {
                        cout << "4. Reference Status: Removed From Library" << endl;
                }

                cout << endl;


}
//This function allows the user to print off a list of all overdue references
void References :: print_overdue_items()
{
	int i, j;
        int counter = 1;

        cout << "List Of References That Are Overdue: " << endl;

        for(i = 0; i < ref_vec.size(); i++)
        {
                if(ref_vec[i].status == 3)
                {
                        cout << "Reference: " << counter << endl;
                        cout << "1. Reference Name: " << setw(4) << left << ref_vec[i].name_of_ref << endl;
                        cout << "2. Reference Author: " << setw(4) << left << ref_vec[i].author_of_ref << endl;
                        cout << "3. Reference Acquisition Number: " << setw(4) << left << ref_vec[i].aq_num << endl;

                        counter++;
                        cout << endl;
                }
        }

}
//This function allows the user to print off a list of all references
void References :: print_all_items()
{
	int i, j;
        int counter = 1;

        cout << "List Of References: " << endl;

        for(i = 0; i < ref_vec.size(); i++)
        {
                cout << "Reference: " << counter << endl;
                cout << "1. Reference Name: " << setw(4) << left << ref_vec[i].name_of_ref << endl;
                cout << "2. Reference Author: " << setw(4) << left << ref_vec[i].author_of_ref << endl;
                cout << "3. Reference Acquisition Number: " << setw(4) << left << ref_vec[i].aq_num << endl;

                counter++;
                cout << endl;
        }

}
//This function acts as the constructor for this class
References :: References()
{
        status = 1;
}
 


//This is the class that will serve as the managers of the "patrons" of the library system
class Patrons
{
        public:
        void add_patron(Patrons patron);
        void remove_patron();
        void edit_info_1patron();
        void print_info_1patron();
        void edit_fineinfo_1patron();
        void print_list_patrons();
        void print_list_patrons_withfines();
        void print_mailing_add();

	private:
        string name_of_patron;
        int ID_num;
        string phone_num;
        string email_add;
        string mailing_add;

        double fine_amount;
	double fine_rate;

	double fine_amount_dvd;
	double fine_rate_dvd;

	double fine_amount_aud_book;
	double fine_rate_aud_book;

	double fine_amount_ref;
        double fine_rate_ref;
	vector<Patrons> patron_vec;

        public:
        Patrons();

};
//This function adds patrons to the registry
void Patrons :: add_patron(Patrons patron)
{
	char name[20];
	bool match = false;
	int i = 0, j = 0;
	int a, b;

		patron_vec.push_back(patron);
		vector<Patrons>::iterator patron_it = patron_vec.begin();

		cout << "Please Enter Name Of Patron: ";
		//cin >> patron_vec[patron_vec.size() - 1].name_of_patron;
		cin.ignore();
                getline(cin, patron_vec[patron_vec.size() - 1].name_of_patron);
		cout << endl;

		cout << "Please Enter ID Number Of Patron: ";
		cin >> patron_vec[patron_vec.size() - 1].ID_num;

		cout << endl;

		cout << "Please Enter Phone Number Of Patron: ";
		cin.ignore();
                getline(cin, patron_vec[patron_vec.size() - 1].phone_num);
		//cin >> patron_vec[patron_vec.size() - 1].phone_num;

		cout << endl;

		cout << "Please Enter Email-Address Of Patron: ";
		//cin.ignore();
                getline(cin, patron_vec[patron_vec.size() - 1].email_add);
		//cin >> patron_vec[patron_vec.size() - 1].email_add;

		cout << endl;

		cout << "Please Emter Mailing Addresss Of Patron: ";
		//cin >> patron_vec[patron_vec.size() - 1].mailing_add;
		//cin.ignore();
                getline(cin, patron_vec[patron_vec.size() - 1].mailing_add);

		cout << endl;

/*
		patron_vec.push_back(patron);
		vector<Patrons>::iterator patron_it = patron_vec.begin();

		cout << "Please Enter Name Of Patron: ";
                cin >> name;

		while(match != true)
                {
			do
			{
				a = name[i];
				b = patron_it->name_of_patron[i];

				a = toupper(a);
				b = toupper(b);

				if (a > b)
				{
					match = true;
					patron_it = patron_vec.begin() + i;
					patron_it->name_of_patron = name;
				}
				if (a < b)
				{
					match = true;
					patron_vec.insert(patron_vec.begin() + (patron_vec.size() - 1), patron);
					patron_it = patron_vec.begin() + (patron_vec.size() - 1);
					patron_it->name_of_patron = name;

					cout << "Please Enter ID Number Of Patron: ";
                			cin >> patron_it->ID_num;

                			cout << endl;

                			cout << "Please Enter Phone Number Of Patron: ";
                			cin >> patron_it->phone_num;

                			cout << endl;

                			cout << "Please Enter Email-Address Of Patron: ";
                			cin >> patron_it->email_add;

                			cout << endl;

                			cout << "Please Emter Mailing Addresss Of Patron: ";
                			cin >> patron_it->mailing_add;

                			cout << endl;

				}
				else
				{
					i++;
					//++patron_it;
				}

			}while( name[i] == patron_it->name_of_patron[i]);
*/

                //}


	

};
//This function removes patrons from the registry
void Patrons :: remove_patron()
{
	int i = 0, j, location;
	int ID_Num;
	char words[20];

	cout << "Please Enter The ID Number Of The Patron That You Would Like To Remove From The System: ";
	cin >> ID_Num;

	for(i = 0; i < patron_vec.size(); i++)
	{
		if(patron_vec[i].ID_num == ID_Num)
		{
			location = i;
			patron_vec.erase(patron_vec.begin() + location);
			cout << "loction: " << location << endl;
			break;
		}
	}


};
//This functio allows you to edit the info on one user defined patron
void Patrons ::edit_info_1patron()
{
	char words[20];
	int i = 0, j, location;
	int ID_Num;
	int response = 10;

	cout << "Please Enter ID Number Of Patron Whom You Would Like To Edit: ";
	cin >> ID_Num;

        for(i = 0; i < patron_vec.size(); i++)
        {
                if(patron_vec[i].ID_num == ID_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

	do
	{

		cout << "*--------------------------------------------------------------------------*" << endl;
        	cout << "|            Welcome To The Patron Account Editing Interface!              |" << endl;
        	cout << "|                                                                          |" << endl;
        	cout << "|                         What Would You Like To Do?                       |" << endl;
        	cout << "|                                                                          |" << endl;
        	cout << "|  1. Edit Patron's Name                                                   |" << endl;
        	cout << "|  2. Edit Patron's ID Number                                              |" << endl;
        	cout << "|  3. Edit Patron's Phone Number                                           |" << endl;
        	cout << "|  4. Edit Patron's Email Address                                          |" << endl;
		cout << "|  5. Edit Patron's Mailing Address                                        |" << endl;
		cout << "|  6. Exit Menu                                                            |" << endl;
        	cout << "*--------------------------------------------------------------------------*" << endl;

		cout << "Response: ";
		cin >> response;
		//scanf("%d%*c", &response);
		switch (response)
		{
			case 1:
				cout << "Please Enter New Patron Name (first name, last name): ";
				//cin >> patron_vec[location].name_of_patron;
				cin.ignore();
                                getline(cin, patron_vec[location].name_of_patron);
				cout << patron_vec[location].name_of_patron << endl;
				cout << endl;
				break;

			case 2:
				cout << "Please Enter New Patron ID Number: ";
				cin >> patron_vec[location].ID_num;
				cout << patron_vec[location].ID_num << endl;
				cout << endl;
				break;

			case 3:
				cout << "Please Enter New Patron Phone Number (with dashes): ";
				//cin >> patron_vec[location].phone_num;
				cin.ignore();
                                getline(cin, patron_vec[location].phone_num);
				cout << patron_vec[location].phone_num << endl;
				cout << endl;
				break;

			case 4:
				cout << "Please Enter New Patron Email Address: ";
				//cin >> patron_vec[location].email_add;
				cin.ignore();
                                getline(cin, patron_vec[location].email_add);
				cout << patron_vec[location].email_add << endl;
				cout << endl;
				break;

			case 5:
				cout << "Please Enter New Patron Mailing Address: ";
				//cin >> patron_vec[location].mailing_add;
				cin.ignore();
				getline(cin, patron_vec[location].mailing_add);
				cout << patron_vec[location].mailing_add << endl;
				//cout << endl;
				break;

			case 6:
				break;

		}
		cin.clear();
	}while(response != 6);
};
//This function allows you to print out the info on one patron
void Patrons :: print_info_1patron()
{
	int i = 0, j, location;
        int ID_Num;
        int response = 0;

        cout << "Please Enter ID Number Of The Patron Whose Information You Would Like To See: ";
        cin >> ID_Num;

        for(i = 0; i < patron_vec.size(); i++)
        {
                if(patron_vec[i].ID_num == ID_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

		cout << "Patron Information: "<< endl;
		cout << endl;
                cout << "1. Patron Name: " << setw(4) << left << patron_vec[location].name_of_patron << endl;
                cout << "2. Patron ID Number: " << setw(4) << left << patron_vec[location].ID_num << endl;
                cout << "3. Patron Phone Number: " << setw(4) << left << patron_vec[location].phone_num << endl;
                cout << "4. Patron Email Address: "  << setw(4) << left << patron_vec[location].email_add << endl;
                cout << "5. Patron's Mailing Address: " << setw(4) << left << patron_vec[location].mailing_add << endl;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
                cout << "6. Patron Fine Amount: " << setw(4) << left << patron_vec[location].fine_amount << endl;

		cout << endl;
};
//This function allows you to edit the fine info on 1 patron
void Patrons :: edit_fineinfo_1patron()
{
	int i = 0, j, location;
        int ID_Num;
        int response = 0;
	int response_2 = 0;
	double fine_amount_add;
	double quarter_pack = 0.25, half_pack = 0.50, threeq_pack = 0.75;

        cout << "Please Enter ID Number Of The Patron Whose Fine Information You Would Like To Edit: ";
        cin >> ID_Num;

        for(i = 0; i < patron_vec.size(); i++)
        {
                if(patron_vec[i].ID_num == ID_Num)
                {
                        location = i;
                        cout << "loction: " << location << endl;
                        break;
                }
        }

	while(response != 5)
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
                cout << "|          Welcome To The Patron Fine Information Editing Interface!       |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|                         What Would You Like To Do?                       |" << endl;
                cout << "|                                                                          |" << endl;
                cout << "|  1. Edit a Patron's Book Fine and Rate                                   |" << endl;
                cout << "|  2. Edit a Patron's DVD  Fine and Rate                                   |" << endl;
		cout << "|  3. Edit a Patron's Audiobook Fine and Rate                              |" << endl;
		cout << "|  4. Edit a Patron's Reference Fine and Rate                              |" << endl;
                cout << "|  5. Exit The Menu                                                        |" << endl;
                cout << "*--------------------------------------------------------------------------*" << endl;

                cout << "Response: ";
                cin >> response;

		if (response == 1)
		{
			//Edit fines for books
			cout << "*--------------------------------------------------------------------------*" << endl;
                	cout << "|          Welcome To The Patron Fine Information Editing Interface!       |" << endl;
                	cout << "|                                                                          |" << endl;
                	cout << "|                         What Would You Like To Do?                       |" << endl;
                	cout << "|                                                                          |" << endl;
                	cout << "|  1. Increment Patron's Fine Amount                                       |" << endl;
                	cout << "|  2. Edit Patron's Fine Rate                                              |" << endl;
                	cout << "|  3. Exit The Menu                                                        |" << endl;
                	cout << "*--------------------------------------------------------------------------*" << endl;

			cout << "Response: ";
			cin >> response;

			switch (response)
			{
				case 1:
					cout << "Please Enter Fine Amount That You Would Like Added To The Current Fine Amount: ";
					cin >> fine_amount_add;
					patron_vec[location].fine_amount += fine_amount_add;
					break;

				case 2:
					cout << "Please Select The Suitable  Fine Rate For Patron: " << endl;
					cout << "1. $0.25 cents daily for missing book deadline by more thar 1 week" << endl;
					cout << "2. $0.50 cents daily for missin book deadline by more than 3 weeks" << endl;
					cout << "3. $0.75 cents daily for missing book deadline by more than 5 weeks" << endl;

					cout << "Response: ";
					cin >> response_2;

					switch (response_2)
					{
						case 1:
							patron_vec[location].fine_rate = 0.25;
							cout << patron_vec[location].fine_rate << endl;
							break;

						case 2:
							patron_vec[location].fine_rate = 0.50;
							cout << patron_vec[location].fine_rate << endl;
							break;

						case 3:
							patron_vec[location].fine_rate = 0.75;
							cout << patron_vec[location].fine_rate << endl;
							break;

						default:
							break;
					}
					break;

				case 3:
					break;
			}
		}

		if (response == 2)
		{	//Edit fines for DVDs
			cout << "*--------------------------------------------------------------------------*" << endl;
                        cout << "|          Welcome To The Patron Fine Information Editing Interface!       |" << endl;
                        cout << "|                                                                          |" << endl;
                        cout << "|                         What Would You Like To Do?                       |" << endl;
                        cout << "|                                                                          |" << endl;
                        cout << "|  1. Increment Patron's Fine Amount                                       |" << endl;
                        cout << "|  2. Edit Patron's Fine Rate                                              |" << endl;
                        cout << "|  3. Exit The Menu                                                        |" << endl;
                        cout << "*--------------------------------------------------------------------------*" << endl;

                        cout << "Response: ";
                        cin >> response;

			switch (response)
			{
				case 1:
                                        cout << "Please Enter Fine Amount That You Would Like Added To The Current Fine Amount: ";
                                        cin >> fine_amount_add;
                                        patron_vec[location].fine_amount_dvd += fine_amount_add;
                                        break;

                                case 2:
                                        cout << "Please Select The Suitable  Fine Rate For Patron: " << endl;
                                        cout << "1. $1.00 cents daily for missing DVD deadline by more thar 1 week" << endl;
                                        cout << "2. $2.50 cents daily for missin DVD deadline by more than 3 weeks" << endl;
                                        cout << "3. $3.00 cents daily for missing DVD deadline by more than 5 weeks" << endl;

                                        cout << "Response: ";
                                        cin >> response_2;

                                        switch (response_2)
                                        {
                                                case 1:
                                                        patron_vec[location].fine_rate_dvd = 1.00;
                                                        cout << patron_vec[location].fine_rate_dvd << endl;
                                                        break;

                                                case 2:
                                                        patron_vec[location].fine_rate_dvd = 2.50;
                                                        cout << patron_vec[location].fine_rate_dvd << endl;
                                                        break;

                                                case 3:
                                                        patron_vec[location].fine_rate_dvd = 3.00;
                                                        cout << patron_vec[location].fine_rate_dvd << endl;
                                                        break;

                                                default:
                                                        break;
                                        }
					break;

                                case 3:
                                        break;


			}

		}

		if(response == 3)
		{	//Edit fines for Audiobooks
			cout << "*--------------------------------------------------------------------------*" << endl;
                        cout << "|          Welcome To The Patron Fine Information Editing Interface!       |" << endl;
                        cout << "|                                                                          |" << endl;
                        cout << "|                         What Would You Like To Do?                       |" << endl;
                        cout << "|                                                                          |" << endl;
                        cout << "|  1. Increment Patron's Fine Amount                                       |" << endl;
                        cout << "|  2. Edit Patron's Fine Rate                                              |" << endl;
                        cout << "|  3. Exit The Menu                                                        |" << endl;
                        cout << "*--------------------------------------------------------------------------*" << endl;

                        cout << "Response: ";
                        cin >> response;

			switch(response)
			{
				case 1:
                                        cout << "Please Enter Fine Amount That You Would Like Added To The Current Fine Amount: ";
                                        cin >> fine_amount_add;
                                        patron_vec[location].fine_amount_aud_book += fine_amount_add;
                                        break;

                                case 2:
                                        cout << "Please Select The Suitable  Fine Rate For Patron: " << endl;
                                        cout << "1. $1.25 cents daily for missing audiobook deadline by more thar 1 week" << endl;
                                        cout << "2. $1.50 cents daily for missin audiobook deadline by more than 3 weeks" << endl;
                                        cout << "3. $1.75 cents daily for missing audiobook deadline by more than 5 weeks" << endl;

                                        cout << "Response: ";
                                        cin >> response_2;

                                        switch (response_2)
                                        {
                                                case 1:
                                                        patron_vec[location].fine_rate_aud_book = 1.25;
                                                        cout << patron_vec[location].fine_rate_aud_book << endl;
                                                        break;

                                                case 2:
                                                        patron_vec[location].fine_rate_aud_book = 1.50;
                                                        cout << patron_vec[location].fine_rate_aud_book << endl;
                                                        break;

                                                case 3:
                                                        patron_vec[location].fine_rate_aud_book = 1.75;
                                                        cout << patron_vec[location].fine_rate_aud_book << endl;
                                                        break;

                                                default:
                                                        break;
                                        }
                                        break;

                                case 3:
                                        break;


			}

		}

		if(response == 4)
		{	//Edit fines for References
			cout << "*--------------------------------------------------------------------------*" << endl;
                        cout << "|          Welcome To The Patron Fine Information Editing Interface!       |" << endl;
                        cout << "|                                                                          |" << endl;
                        cout << "|                         What Would You Like To Do?                       |" << endl;
                        cout << "|                                                                          |" << endl;
                        cout << "|  1. Increment Patron's Fine Amount                                       |" << endl;
                        cout << "|  2. Edit Patron's Fine Rate                                              |" << endl;
                        cout << "|  3. Exit The Menu                                                        |" << endl;
                        cout << "*--------------------------------------------------------------------------*" << endl;

                        cout << "Response: ";
                        cin >> response;

			switch (response)
			{
				case 1:
                                        cout << "Please Enter Fine Amount That You Would Like Added To The Current Fine Amount: ";
                                        cin >> fine_amount_add;
                                        patron_vec[location].fine_amount_ref += fine_amount_add;
                                        break;

                                case 2:
                                        cout << "Please Select The Suitable  Fine Rate For Patron: " << endl;
                                        cout << "1. $0.50 cents daily for missing reference deadline by more thar 1 week" << endl;
                                        cout << "2. $0.75 cents daily for missin reference deadline by more than 3 weeks" << endl;
                                        cout << "3. $1.00 cents daily for missing reference deadline by more than 5 weeks" << endl;

                                        cout << "Response: ";
                                        cin >> response_2;

                                        switch (response_2)
                                        {
                                                case 1:
                                                        patron_vec[location].fine_rate_ref = 0.50;
                                                        cout << patron_vec[location].fine_rate_ref << endl;
                                                        break;

                                                case 2:
                                                        patron_vec[location].fine_rate_ref = 0.75;
                                                        cout << patron_vec[location].fine_rate_ref << endl;
                                                        break;

                                                case 3:
                                                        patron_vec[location].fine_rate_ref = 1.00;
                                                        cout << patron_vec[location].fine_rate_ref << endl;
                                                        break;

                                                default:
                                                        break;
                                        }
                                        break;

                                case 3:
					break;


			}
		}
	}


};
//This function allows you to print a list of all patrons in the system
void Patrons :: print_list_patrons()
{
	int i, j;
	int counter = 1;

	cout << "List Of Patrons:" << endl << endl;

	for(i = 0; i < patron_vec.size(); i++)
        {
		cout << "Patron: " << counter << endl;
		cout << "1. Patron Name: " << setw(4) << left << patron_vec[i].name_of_patron << endl;
                cout << "2. Patron ID Number: " << setw(4) << left << patron_vec[i].ID_num << endl;
                cout << "3. Patron Phone Number: " << setw(4) << left << patron_vec[i].phone_num << endl;
                cout << "4. Patron Email Address: "  << setw(4) << left << patron_vec[i].email_add << endl;

		counter++;
		cout << endl;
        }

};
//This function allows you to print a list of all patrons with fines
void Patrons :: print_list_patrons_withfines()
{
	int i, j;
        int counter = 1;

	cout << "List Of Patrons With Outstanding Fines: ";

	for(i = 0; i < patron_vec.size(); i++)
	{
		if(patron_vec[i].fine_amount > 0)
		{
			cout << "Patron: " << counter << endl;
                	cout << "1. Patron Name: " << setw(4) << left << patron_vec[i].name_of_patron << endl;
                	cout << "2. Patron ID Number: " << setw(4) << left << patron_vec[i].ID_num << endl;
                	cout << "3. Patron Phone Number: " << setw(4) << left << patron_vec[i].phone_num << endl;
                	cout << "4. Patron Email Address: "  << setw(4) << left << patron_vec[i].email_add << endl;

			counter++;
			cout << endl;
		}
	}
};
//This function allows the user to print the mailing address of all of the patrons
void Patrons :: print_mailing_add()
{
	int i, j;
        int counter = 1;

        cout << "List Of Patrons's Mailing Addresses:" << endl << endl;

        for(i = 0; i < patron_vec.size(); i++)
        {
                cout << "Patron: " << counter << endl;
                cout << "1. Patron Name: " << setw(4) << left << patron_vec[i].name_of_patron << endl;
                cout << "2. Patron ID Number: " << setw(4) << left << patron_vec[i].ID_num << endl;
		cout << "3. Patron Mailing Address: " << setw(4) << left << patron_vec[i].mailing_add << endl;
                counter++;
                cout << endl;
        }


};
//This is the default constructor for the patrons class
Patrons :: Patrons()
{
	fine_amount = 0;
};
//This class will serve as the manager and parent of the relationships between both the patrons and items (rentals, etc.)
class Items_C_and_R
{
	public:
	virtual void remove_patron_from_item() = 0;
	virtual void print_checkret_info_p_item() = 0;

};
//This class will act as the class that will house all of the information pertaining to book rentals
class Checks_and_Returns : public Items_C_and_R
{
        public:
        void connect_patron_to_book(Books book, Patrons patron, Checks_and_Returns check_and_return);
        void remove_patron_from_book();
        void print_checkret_info_p_b();

	virtual void remove_patron_from_item();
        virtual void print_checkret_info_p_item();

	private:
        int book_ID;
        int patron_ID;
        string date_to_return;
	vector<Checks_and_Returns> c_r_vec;

        public:
        Checks_and_Returns();
};
//Dummy classes
void Checks_and_Returns :: remove_patron_from_item()
{
	cout << "poop" << endl;
}
void Checks_and_Returns :: print_checkret_info_p_item()
{
	cout << "poop" << endl;
}
//This function connects both a patron and a book together in a rental relationship
void Checks_and_Returns :: connect_patron_to_book(Books book, Patrons patron, Checks_and_Returns check_and_return)
{
	int i, j, location;

	c_r_vec.push_back(check_and_return);

	cout << "Please Enter The Acquisition Number Of The Book: ";
	cin >> c_r_vec[c_r_vec.size() - 1].book_ID;

	cout << "Please Enter The ID Number Of The Patron: ";
	cin >> c_r_vec[c_r_vec.size() - 1].patron_ID;

	cout << "Please Enter The Date That Book Is Due By (Preferabley in format: MM/DD/YY): ";
	cin.ignore();
        getline(cin, c_r_vec[c_r_vec.size() - 1].date_to_return);


};
// This function removes a patron and a book from a rental relationship
void Checks_and_Returns :: remove_patron_from_book()
{
	int i, j;
	int ID_patron;
	int location;
	cout << "Please Enter ID Number Of Patron To Disband Rental: ";
	cin >> ID_patron;

	for(i = 0; i < c_r_vec.size(); i++)
        {
                if(c_r_vec[i].patron_ID == ID_patron)
                {
                        location = i;
			c_r_vec.erase(c_r_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

};
//This function prints all of the information on a patron's rental inquiries
void Checks_and_Returns :: print_checkret_info_p_b()
{
	int i, j;
        int ID_patron;
        int counter = 1;
        cout << "Please Enter ID Number Of Patron To Look Up Rental Information: ";
        cin >> ID_patron;

	cout << "Rental Information On Patron ID: " << ID_patron << endl;

        for(i = 0; i < c_r_vec.size(); i++)
        {
                if(c_r_vec[i].patron_ID == ID_patron)
                {
                        cout << "Book " << counter << " ID: " << c_r_vec[i].book_ID << endl;
		        cout << "Date Book Is Due By: " << c_r_vec[i].date_to_return << endl;
			cout << endl; 
                }
        }
	cout << endl;


};

//This is the default constructor for the checks and returns class
Checks_and_Returns :: Checks_and_Returns()
{
        date_to_return = "00/00/00";
};

//This class will act as the class that will house all of the information pertaining to dvd rentals
class DVD_C_and_R : public Items_C_and_R
{
	public:
	void connect_patron_to_DVD(DVD_C_and_R dvd_c_and_r);
	void remove_patron_from_item();
	void print_checkret_info_p_item();

	private:
        int dvd_ID;
        int patron_ID;
        string date_to_return;
        vector<DVD_C_and_R> dvdcr_vec;

        public:
        DVD_C_and_R();
};
//This function connects a patron to a dvd
void DVD_C_and_R :: connect_patron_to_DVD(DVD_C_and_R dvd_c_and_r)
{
	int i, j, location;

        dvdcr_vec.push_back(dvd_c_and_r);

        cout << "Please Enter The Acquisition Number Of The DVD: ";
        cin >> dvdcr_vec[dvdcr_vec.size() - 1].dvd_ID;

        cout << "Please Enter The ID Number Of The Patron: ";
        cin >> dvdcr_vec[dvdcr_vec.size() - 1].patron_ID;

        cout << "Please Enter The Date That Book Is Due By (Preferabley in format: MM/DD/YY): ";
        cin.ignore();
        getline(cin, dvdcr_vec[dvdcr_vec.size() - 1].date_to_return);


}
//This function removes a patron from a dvd
void DVD_C_and_R :: remove_patron_from_item()
{
	int i, j;
        int ID_patron;
        int location;
        cout << "Please Enter ID Number Of Patron To Disband Rental: ";
        cin >> ID_patron;

        for(i = 0; i < dvdcr_vec.size(); i++)
        {
                if(dvdcr_vec[i].patron_ID == ID_patron)
                {
                        location = i;
                        dvdcr_vec.erase(dvdcr_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

}
//This function print off the rental info on a patron and a dvd
void DVD_C_and_R :: print_checkret_info_p_item()
{
	int i, j;
        int ID_patron;
        int counter = 1;
        cout << "Please Enter ID Number Of Patron To Look Up Rental Information: ";
        cin >> ID_patron;

        cout << "Rental Information On Patron ID: " << ID_patron << endl;

        for(i = 0; i < dvdcr_vec.size(); i++)
        {
                if(dvdcr_vec[i].patron_ID == ID_patron)
                {
                        cout << "DVD " << counter << " ID: " << dvdcr_vec[i].dvd_ID << endl;
                        cout << "Date DVD Is Due By: " << dvdcr_vec[i].date_to_return << endl;
                        cout << endl; 
                }
        }
        cout << endl;

}

//This is the default constructor for the checks and returns class
DVD_C_and_R :: DVD_C_and_R()
{
        date_to_return = "00/00/00";
};

//This class will act as the class that will house all of the information pertaining to Audiobook rentals
class Audiobook_C_and_R : public Items_C_and_R
{
	public:
        void connect_patron_to_aud(Audiobook_C_and_R audiobook_c_and_r);
        void remove_patron_from_item();
        void print_checkret_info_p_item();

        private:
        int aud_ID;
        int patron_ID;
        string date_to_return;
        vector<Audiobook_C_and_R> audcr_vec;

        public:
        Audiobook_C_and_R();
};
//This functio connects a patron to an audiobook
void Audiobook_C_and_R :: connect_patron_to_aud(Audiobook_C_and_R audiobook_c_and_r)
{
	int i, j, location;

        audcr_vec.push_back(audiobook_c_and_r);

        cout << "Please Enter The Acquisition Number Of The Audiobook: ";
        cin >> audcr_vec[audcr_vec.size() - 1].aud_ID;

        cout << "Please Enter The ID Number Of The Patron: ";
        cin >> audcr_vec[audcr_vec.size() - 1].patron_ID;

        cout << "Please Enter The Date That Audiobook Is Due By (Preferabley in format: MM/DD/YY): ";
        cin.ignore();
        getline(cin, audcr_vec[audcr_vec.size() - 1].date_to_return);
}
//This function removes a patron from an audiobook
void Audiobook_C_and_R :: remove_patron_from_item()
{
	int i, j;
        int ID_patron;
        int location;
        cout << "Please Enter ID Number Of Patron To Disband Rental: ";
        cin >> ID_patron;

        for(i = 0; i < audcr_vec.size(); i++)
        {
                if(audcr_vec[i].patron_ID == ID_patron)
                {
                        location = i;
                        audcr_vec.erase(audcr_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

}
//This function prints out info pertaining to an audiobook rental
void Audiobook_C_and_R :: print_checkret_info_p_item()
{
	int i, j;
        int ID_patron;
        int counter = 1;
        cout << "Please Enter ID Number Of Patron To Look Up Rental Information: ";
        cin >> ID_patron;

        cout << "Rental Information On Patron ID: " << ID_patron << endl;

        for(i = 0; i < audcr_vec.size(); i++)
        {
                if(audcr_vec[i].patron_ID == ID_patron)
                {
                        cout << "DVD " << counter << " ID: " << audcr_vec[i].aud_ID << endl;
                        cout << "Date DVD Is Due By: " << audcr_vec[i].date_to_return << endl;
                        cout << endl; 
                }
        }
        cout << endl;


}

//This is the default constructor for the checks and returns (audiobooks) class
Audiobook_C_and_R :: Audiobook_C_and_R()
{
        date_to_return = "00/00/00";
};

//This class will act as the class that will house all of the information pertaining to references
class Reference_C_and_R : public Items_C_and_R
{
	public:
        void connect_patron_to_ref(Reference_C_and_R reference_c_and_R);
        void remove_patron_from_item();
        void print_checkret_info_p_item();

        private:
        int ref_ID;
        int patron_ID;
        string date_to_return;
        vector<Reference_C_and_R> refcr_vec;

        public:
        Reference_C_and_R();

};
//This function connects a user to a reference
void Reference_C_and_R :: connect_patron_to_ref(Reference_C_and_R reference_c_and_r)
{
	int i, j, location;

        refcr_vec.push_back(reference_c_and_r);

        cout << "Please Enter The Acquisition Number Of The Reference: ";
        cin >> refcr_vec[refcr_vec.size() - 1].ref_ID;

        cout << "Please Enter The ID Number Of The Patron: ";
        cin >> refcr_vec[refcr_vec.size() - 1].patron_ID;

        cout << "Please Enter The Date That Reference Is Due By (Preferabley in format: MM/DD/YY): ";
        cin.ignore();
        getline(cin, refcr_vec[refcr_vec.size() - 1].date_to_return);
}
//This function removes a patron from a reference
void Reference_C_and_R :: remove_patron_from_item()
{
	int i, j;
        int ID_patron;
        int location;
        cout << "Please Enter ID Number Of Patron To Disband Rental: ";
        cin >> ID_patron;

        for(i = 0; i < refcr_vec.size(); i++)
        {
                if(refcr_vec[i].patron_ID == ID_patron)
                {
                        location = i;
                        refcr_vec.erase(refcr_vec.begin() + location);
                        cout << "loction: " << location << endl;
                        break;
                }
        }

}
//This function prints out info pertaining to a reference rental
void Reference_C_and_R :: print_checkret_info_p_item()
{
	int i, j;
        int ID_patron;
        int counter = 1;
        cout << "Please Enter ID Number Of Patron To Look Up Rental Information: ";
        cin >> ID_patron;

        cout << "Rental Information On Patron ID: " << ID_patron << endl;

        for(i = 0; i < refcr_vec.size(); i++)
        {
                if(refcr_vec[i].patron_ID == ID_patron)
                {
                        cout << "Reference " << counter << " ID: " << refcr_vec[i].ref_ID << endl;
                        cout << "Date Reference Is Due By: " << refcr_vec[i].date_to_return << endl;
                        cout << endl; 
                }
        }
        cout << endl;
}

//This is the default constructor for the checks and returns class (references)
Reference_C_and_R :: Reference_C_and_R()
{
        date_to_return = "00/00/00";
};

int main()
{
	//Declare instances of necessary objects
	Patrons patrons;

	Books books;
	DVDs dvds;
	Audio_Books audio_books;
	References references;

//	Items *item_book_ptr = &books;
        Items *item_DVD_ptr = &dvds;
        Items *item_aud_book_ptr = &audio_books;
	Items *item_ref_ptr = &references;

	Checks_and_Returns checks_and_returns;
	DVD_C_and_R dvd_c_and_r;
	Audiobook_C_and_R audiobook_c_and_r;
	Reference_C_and_R reference_c_and_r;

	Items_C_and_R *item_DVDcr_ptr = &dvd_c_and_r;
	Items_C_and_R *item_audcr_ptr = &audiobook_c_and_r;
	Items_C_and_R *item_refcr_ptr = &reference_c_and_r;
	//Check_and_Return check_and_return;

	int response = 0;

	//Craft a dense menu screen that will take care of user input
	cout << "*--------------------------------------------------------*" << endl;
	cout << "|		Computer Science Depatrment		 |" << endl;
	cout << "|			CSCE 1040			 |" << endl;
	cout << "|		        Homework 5			 |" << endl;
	cout << "|			Aaron Batch			 |" << endl;
	cout << "|		  AaronBatch@my.unt.edu			 |" << endl;
	cout << "*--------------------------------------------------------*" << endl;

	while (response != 4)
	{
		cout << "*--------------------------------------------------------------------------*" << endl;
		cout << "|	      Welcome To The Smallsville Library Management System!        |" << endl;
		cout << "|									   |" << endl;
		cout << "|			   What Would You Like To Do?			   |" << endl;
		cout << "|									   |" << endl;
		cout << "|  1. Go To The Patron Management Interface			           |" << endl;
		cout << "|  2. Go To The Item Management Interface				   |" << endl;
		cout << "|  3. Go To The Item Checkouts and Returns Interface			   |" << endl;
		cout << "|  4. Save and Exit							   |" << endl;
		cout << "*--------------------------------------------------------------------------*" << endl;

		cout << endl;
		cout << "Response: ";

		cin >> response;

		cout << endl;

		if (response == 1)
		{
			while (response != 9)
			{
				cout << "*------------------------------------------------------------------------------*" << endl;
				cout << "|	              Welcome To The Patron Management Interface!	       |" << endl;
				cout << "|							   		       |" << endl;
				cout << "|	                      What Would You Like To Do?		       |" << endl;
				cout << "|							   		       |" << endl;
				cout << "|  1. Add A Patron To The System			   		       |" << endl;
				cout << "|  2. Remove A Patron To The System			   		       |" << endl;
				cout << "|  3. Edit A Patron's Account Information		   		       |" << endl;
				cout << "|  4. Edit A Patron's Outstandind Fine Information        		       |" << endl;
				cout << "|  5. Print Information On A Single Patron				       |" << endl;
				cout << "|  6. Print An Alphabetical List Of All Patrons	   	                       |" << endl;
				cout << "|  7. Print An Alphabetical List Of All Patrons With Outstanding Fines	       |" << endl;
				cout << "|  8. Print out an alphabetical list of mailing addresses for each patron      |" << endl;
				cout << "|  9. Exit This Menu							       |" << endl;
				cout << "*------------------------------------------------------------------------------*" << endl;

				cout << endl;
				cout << "Response: ";

				cin >> response;

				cout << endl;

				switch (response)
				{
					case 1:
						patrons.add_patron(patrons);
						break;

					case 2:
						patrons.remove_patron();
						break;

					case 3:
						patrons.edit_info_1patron();
						break;

					case 4:
						patrons.edit_fineinfo_1patron();
						break;

					case 5:
						patrons.print_info_1patron();
						break;

					case 6:
						patrons.print_list_patrons();
						break;

					case 7:
						patrons.print_list_patrons_withfines();
						break;

					case 8:
						patrons.print_mailing_add();
						break;

					case 9:
						break;
				}
			}
		}

		if (response == 2)
		{

			while (response != 5)
			{
				        cout << "*------------------------------------------------------------------------------*" << endl;
                                        cout << "|                   Welcome To The Item Management Interface!                  |" << endl;
                                        cout << "|                                                                              |" << endl;
                                        cout << "|                           What Would You Like To Do?                         |" << endl;
                                        cout << "|                                                                              |" << endl;
                                        cout << "|  1. Go To The Book Management Interface                                      |" << endl;
                                        cout << "|  2. Go To The DVD Management Interface                                       |" << endl;
                                        cout << "|  3. Go To The Audiobook Management Interface                                 |" << endl;
                                        cout << "|  4. Go To The Reference Management Interface                                 |" << endl;
                                        cout << "|  5. Exit This Menu                                                           |" << endl;
                                        cout << "*------------------------------------------------------------------------------*" << endl;

                                        cout << endl;
                                        cout << "Response: ";

                                        cin >> response;

                                        cout << endl;

				if (response == 1)
				{
					while (response != 7)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                		cout << "|                   Welcome To The Book Management Interface!                  |" << endl;
                                		cout << "|                                                                              |" << endl;
                                		cout << "|                           What Would You Like To Do?                         |" << endl;
                                		cout << "|                                                                              |" << endl;
                                		cout << "|  1. Add A Book To The System                                                 |" << endl;
                                		cout << "|  2. Remove A Book From The System                                            |" << endl;
                                		cout << "|  3. Edit A Book's Account Information                                        |" << endl;
                                		cout << "|  4. Print Information On A Specific Book                                     |" << endl;
                                		cout << "|  5. Print List Of All Overdue Books                                          |" << endl;
						cout << "|  6. Print List Of All Books                                          	|" << endl;
                                		cout << "|  7. Exit This Menu                                                           |" << endl;
                                		cout << "*------------------------------------------------------------------------------*" << endl;

						cout << endl;
						cout << "Response: ";

						cin >> response;

						cout << endl;

						switch (response)
						{
							case 1:
								books.add_book(books);
								break;

							case 2:
								books.remove_book();
								break;

							case 3:
								books.edit_info_1book();
								break;

							case 4:
								books.print_info_1book();
								break;

							case 5:
								books.print_overdue_books();
								break;

							case 6:
								books.print_all_books();
								break;

							case 7:
								break;
						}
					}
				}

				if (response == 2)
				{
					while (response != 7)
                                        {
                                                cout << "*------------------------------------------------------------------------------*" << endl;
                                                cout << "|                   Welcome To The DVD Management Interface!                   |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|                           What Would You Like To Do?                         |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|  1. Add A DVD To The System                                                  |" << endl;
                                                cout << "|  2. Remove A DVD From The System                                             |" << endl;
                                                cout << "|  3. Edit A DVD's Account Information                                         |" << endl;
                                                cout << "|  4. Print Information On A Specific DVD                                      |" << endl;
                                                cout << "|  5. Print List Of All Overdue DVDs                                           |" << endl;
						cout << "|  6. Print List Of All DVDs                                           	|" << endl;
                                                cout << "|  7. Exit This Menu                                                           |" << endl;
                                                cout << "*------------------------------------------------------------------------------*" << endl;

                                                cout << endl;
                                                cout << "Response: ";

                                                cin >> response;

                                                cout << endl;

                                                switch (response)
                                                {
                                                        case 1:
                                                                dvds.add_DVD(dvds);
                                                                break;

                                                        case 2:
                                                                item_DVD_ptr->remove_item();
                                                                break;

                                                        case 3:
                                                                item_DVD_ptr->edit_info_1item();
                                                                break;

                                                        case 4:
                                                                item_DVD_ptr->print_info_1item();
                                                                break;

                                                        case 5:
                                                                item_DVD_ptr->print_overdue_items();
                                                                break;

                                                        case 6:
                                                                item_DVD_ptr->print_all_items();
								break;

							case 7:
								break;
                                                }
					}

				}

				if (response == 3)
				{
					while (response != 7)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                                cout << "|                 Welcome To The Audiobook Management Interface!               |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|                           What Would You Like To Do?                         |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|  1. Add An Audiobook To The System                                           |" << endl;
                                                cout << "|  2. Remove An Audiobook From The System                                      |" << endl;
                                                cout << "|  3. Edit An Audiobook's Account Information                                  |" << endl;
                                                cout << "|  4. Print Information On A Specific Audiobook                                |" << endl;
                                                cout << "|  5. Print List Of All Overdue Audiobooks                                     |" << endl;
                                                cout << "|  6. Print List Of All Audiobooks                                             |" << endl;
                                                cout << "|  7. Exit This Menu                                                           |" << endl;
                                                cout << "*------------------------------------------------------------------------------*" << endl;

                                                cout << endl;
                                                cout << "Response: ";

                                                cin >> response;

                                                cout << endl;

                                                switch (response)
                                                {
                                                        case 1:
                                                                audio_books.add_aud_book(audio_books);
                                                                break;

                                                        case 2:
                                                                item_aud_book_ptr->remove_item();
                                                                break;

                                                        case 3:
                                                                item_aud_book_ptr->edit_info_1item();
                                                                break;

                                                        case 4:
                                                                item_aud_book_ptr->print_info_1item();
                                                                break;

                                                        case 5:
                                                                item_aud_book_ptr->print_overdue_items();
                                                                break;

                                                        case 6:
                                                                item_aud_book_ptr->print_all_items();
                                                                break;

                                                        case 7:
                                                                break;
                                                }

					}
				}

				if (response == 4)
				{
					while (response != 7)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                                cout << "|                   Welcome To The Reference Management Interface!             |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|                           What Would You Like To Do?                         |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|  1. Add A Reference To The System                                            |" << endl;
                                                cout << "|  2. Remove A Reference From The System                                       |" << endl;
                                                cout << "|  3. Edit A Reference's Account Information                                   |" << endl;
                                                cout << "|  4. Print Information On A Specific Reference                                |" << endl;
                                                cout << "|  5. Print List Of All Overdue References                                     |" << endl;
                                                cout << "|  6. Print List Of All References                                             |" << endl;
                                                cout << "|  7. Exit This Menu                                                           |" << endl;
                                                cout << "*------------------------------------------------------------------------------*" << endl;

                                                cout << endl;
                                                cout << "Response: ";

                                                cin >> response;

                                                cout << endl;

                                                switch (response)
                                                {
                                                        case 1:
                                                                references.add_ref(references);
                                                                break;

                                                        case 2:
                                                                item_ref_ptr->remove_item();
                                                                break;

                                                        case 3:
                                                                item_ref_ptr->edit_info_1item();
                                                                break;

                                                        case 4:
                                                                item_ref_ptr->print_info_1item();
                                                                break;

                                                        case 5:
                                                                item_ref_ptr->print_overdue_items();
                                                                break;

                                                        case 6:
                                                                item_ref_ptr->print_all_items();
                                                                break;

                                                        case 7:
                                                                break;
                                                }

					}
				}

			}
		}

		if (response == 3)
		{
			while (response != 6)
			{
				        cout << "*------------------------------------------------------------------------------*" << endl;
                                        cout << "|          Welcome To The Item Checkouts and Returns Management Interface!     |" << endl;
                                        cout << "|                                                                              |" << endl;
                                        cout << "|                           What Would You Like To Do?                         |" << endl;
                                        cout << "|                                                                              |" << endl;
                                        cout << "|  1. Manage Book Rentals                                               	|" << endl;
                                        cout << "|  2. Manage DVD Rentals                        				|" << endl;
                                        cout << "|  3. Manage Audiobook Rentals						        |" << endl;
					cout << "|  3. Manage Reference Rentals                                                 |" << endl;
                                        cout << "|  6. Exit This Menu                                                           |" << endl;
                                        cout << "*------------------------------------------------------------------------------*" << endl;

					cout << endl;
                                        cout << "Response: ";

                                        cin >> response;

                                        cout << endl;

				if(response == 1)
				{ 
					while (response != 5)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                		cout << "|                    Welcome To The Book Rental Interface!                     |" << endl;
                                		cout << "|                                                                              |" << endl;
                                		cout << "|                           What Would You Like To Do?                         |" << endl;
                                		cout << "|                                                                              |" << endl;
                                		cout << "|  1. Connect A Patron To A Book                                               |" << endl;
                                		cout << "|  2. Remove The Connection Between A Patron And A Book                        |" << endl;
                                		cout << "|  3. Print Checkout Or Return Information On A Patron and Their Books         |" << endl;
                                		cout << "|  5. Exit This Menu                                                           |" << endl;
                                		cout << "*------------------------------------------------------------------------------*" << endl;

						cout << endl;
						cout << "Response: ";

						cin >> response;

						cout << endl;

						switch (response)
						{
							case 1:
								checks_and_returns.connect_patron_to_book(books, patrons, checks_and_returns);
								break;

							case 2:
								checks_and_returns.remove_patron_from_book();
								break;

							case 3:
								checks_and_returns.print_checkret_info_p_b();
								break;

							case 5:
								break;

						}
					}
				}

				if(response == 2)
				{
					while (response != 5)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                                cout << "|                       Welcome To The DVD Rental Interface!                   |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|                           What Would You Like To Do?                         |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|  1. Connect A Patron To A DVD                                                |" << endl;
                                                cout << "|  2. Remove The Connection Between A Patron And A DVD                         |" << endl;
                                                cout << "|  3. Print Checkout Or Return Information On A Patron and Their DVD           |" << endl;
                                                cout << "|  5. Exit This Menu                                                           |" << endl;
                                                cout << "*------------------------------------------------------------------------------*" << endl;

                                                cout << endl;
                                                cout << "Response: ";

                                                cin >> response;

                                                cout << endl;

						switch (response)
                                                {
                                                        case 1:
                                                                dvd_c_and_r.connect_patron_to_DVD(dvd_c_and_r);
                                                                break;

                                                        case 2:
                                                                item_DVDcr_ptr->remove_patron_from_item();
                                                                break;

                                                        case 3:
                                                                item_DVDcr_ptr->print_checkret_info_p_item();
                                                                break;

                                                        case 5:
                                                                break;

                                                }


					}
				}

				if(response == 3)
				{
					while (response != 5)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                                cout << "|                   Welcome To The Audiobook Rental Interface!                 |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|                           What Would You Like To Do?                         |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|  1. Connect A Patron To An Audiobook                                         |" << endl;
                                                cout << "|  2. Remove The Connection Between A Patron And An Audiobook                  |" << endl;
                                                cout << "|  3. Print Checkout Or Return Information On A Patron and Their Audiobook     |" << endl;
                                                cout << "|  5. Exit This Menu                                                           |" << endl;
                                                cout << "*------------------------------------------------------------------------------*" << endl;

                                                cout << endl;
                                                cout << "Response: ";

                                                cin >> response;

                                                cout << endl;

						switch (response)
                                                {
                                                        case 1:
                                                                audiobook_c_and_r.connect_patron_to_aud(audiobook_c_and_r);
                                                                break;

                                                        case 2:
                                                                item_audcr_ptr->remove_patron_from_item();
                                                                break;

                                                        case 3:
                                                                item_audcr_ptr->print_checkret_info_p_item();
                                                                break;

                                                        case 5:
                                                                break;

                                                }


					}
				}

				if(response == 4)
				{
					while(response != 5)
					{
						cout << "*------------------------------------------------------------------------------*" << endl;
                                                cout << "|                   Welcome To The Reference Rental Interface!                 |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|                           What Would You Like To Do?                         |" << endl;
                                                cout << "|                                                                              |" << endl;
                                                cout << "|  1. Connect A Patron To A Reference                                          |" << endl;
                                                cout << "|  2. Remove The Connection Between A Patron And A Reference                   |" << endl;
                                                cout << "|  3. Print Checkout Or Return Information On A Patron and Their Reference     |" << endl;
                                                cout << "|  5. Exit This Menu                                                           |" << endl;
                                                cout << "*------------------------------------------------------------------------------*" << endl;

                                                cout << endl;
                                                cout << "Response: ";

                                                cin >> response;

                                                cout << endl;

						switch (response)
                                                {
                                                        case 1:
                                                                reference_c_and_r.connect_patron_to_ref(reference_c_and_r);
                                                                break;

                                                        case 2:
                                                                item_refcr_ptr->remove_patron_from_item();
                                                                break;

                                                        case 3:
                                                                item_refcr_ptr->print_checkret_info_p_item();
                                                                break;

                                                        case 5:
                                                                break;

                                                }


					}
				}
			}
		}

		if (response == 4)
        	{

			cout << "PROGRAM TERMINATED" << endl;
			break;
        	}
	}

return 0;
}

void save_and_exit()
{
	cout << "poop" << endl;
}
