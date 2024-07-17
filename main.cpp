#include <iostream>
#include "movie-manager.h"

using namespace std;

void print_menu()
{
  cout << endl
       << "Please Select the option you want to perform" << endl;
  cout << "0 - Exit\t"
       << "1 - List\t"
       << "2 - Search\t"
       << "3 - Add a Movie\t" << endl
       << "4 - Delete a Movie\t" << endl
       << "> ";
}

void ignore_newline()
{
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool get_valid_int(int &num)
{
  cin >> num;
  if (cin.fail())
  {
    cin.clear();
    ignore_newline();
    return false;
  }
  return true;
}

int main()
{
  cout << endl
       << ".:: Welcome to Movie Manager! ::." << endl
       << endl;
  MovieManager manager;
  int choice;
  int id_del;
  string search_name;
  string add_name;
  string add_genre;
  int add_release_year;

  manager.create_examples();
  print_menu();

  while (choice != 0)
  {
    while (!get_valid_int(choice))
    {
      cout << "Invalid input! Please enter a number: ";
    }

    switch (choice)
    {
    case 0:
      cout << "GoodBye!" << endl;
      exit(0);
    case 1:
      manager.list_movies();
      print_menu();
      break;
    case 2:
      cout << "please type the movie name : ";
      cin >> search_name;
      manager.search(search_name);
      print_menu();
      break;
    case 3:
      cout << "Add a new movie to the Database:" << endl;
      cout << "Movie title: ";
      ignore_newline();
      getline(cin, add_name);
      cout << "Movie genre: ";
      getline(cin, add_genre);
      cout << "Movie release year: ";
      cin >> add_release_year;
      cout << endl;
      manager.add(add_name, add_genre, add_release_year);
      cout << "Added new movie:  " << add_name << endl;
      print_menu();
      break;
    case 4:
      cout << "Please input the ID of the movie you wish to delete" << endl;
      cout << "ID: ";
      cin >> id_del;
      if (id_del > 0)
      {
        manager.del(id_del);
      }
      else
      {
        cout << "Please input a valid ID!";
      }
      print_menu();
      break;
    default:
      cout << "Wrong Choice please select carefully!" << endl;
      print_menu();
      break;
    }
  }

  return 0;
}
