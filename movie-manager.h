#include <iostream>
#include <vector>
#include "movie.h"
using namespace std;

class MovieManager
{
public:
  vector<Movie> movies;

  void add(string title, string genre, int release_year)
  {
    Movie m;
    m.id = this->movies.size() + 1;
    m.title = title;
    m.genre = genre;
    m.release_year = release_year;
    this->movies.push_back(m);
  }

  void del(int id)
  {
    int i = 0;
    for (const auto &m : this->movies)
    {
      if (m.id == id)
      {
        cout << "Movie " << m.title << " Deleted!" << endl;
        this->movies.erase(this->movies.begin() + i);
        break;
      }
      i++;
    }
  }

  void search(const string text)
  {
    vector<Movie> foundMovies;
    for (const auto &movie : this->movies)
    {
      size_t found = movie.title.find(text);
      if (found != string::npos)
      {
        foundMovies.push_back(movie);
      }
    }
    if (foundMovies.size() > 0)
    {
      cout << "Found Movies : " << endl;
      this->print_movies(foundMovies);
    }
    else
    {
      cout << "No Movies Found with this name!" << endl;
    }
  }

  void print_movies(vector<Movie> &printList)
  {
    for (const auto &movie : printList)
    {
      cout << "---" << endl;
      cout << "ID: " << movie.id << endl;
      cout << "Title: " << movie.title << endl;
      cout << "Genre: " << movie.genre << endl;
      cout << "Release Year: " << movie.release_year << endl;
      cout << "" << endl;
    }
  }

  void list_movies()
  {
    cout << "Here's the list of available movies" << endl;
    cout << "Movies listed in DB: " << this->movies.size() << endl;
    this->print_movies(this->movies);
  }

  void create_examples()
  {
    this->add("The Matrix", "Sci-fi, Action", 1999);
    this->add("Fight Club", "Thriller, Action", 1999);
    this->add("Pulp Fiction", "Crime, Thriller", 1994);
    this->add("The Thing", "Horror, Sci-fi", 1982);
  }
};
