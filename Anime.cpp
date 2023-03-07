#include "Anime.h"
#include <iostream>
#include <cstring>
Anime::Anime()
{
	/**
	 * .
	 * null constructor
	 */
	episodes = 0;
	rating = 0;
	title = "";
	studio = "";
}

Anime::Anime(int episodes_, std::string title_, std::string studio_, int rating_)
{
	/**
	 * .
	 * parametric constructor
	 * \param episodes_ number of episodes
	 * \param title_ title
	 * \param studio_ studio
	 * \param rating_ rating
	 */
	episodes = episodes_;
	title = title_;
	studio = studio_;
	rating = rating_;
}

Anime::Anime(const Anime& other)
{
	/**
	 * .
	 * copy constructor
	 * \param other anime we want to copy
	 */
	this->episodes = other.episodes;
	this->rating = other.rating;
	this->studio = other.studio;
	this->title = other.title;
}

int Anime::getEpisodes() const
{
	/**
	 * .
	 * getter 
	 * \return number of episodes 
	 */
	return this->episodes;
}

int Anime::getRating() const
{
	/**
	 * .
	 * getter
	 * \return rating
	 */
	return this->rating;
}

std::string Anime::getTitle()
{
	/**
	 * .
	 * getter
	 * \return title 
	 */
	return this->title;
}

std::string Anime::getStudio()
{
	/**
	 * .
	 * getter
	 * \return studio 
	 */
	return this->studio;
}

void Anime::setEpisodes(int e)
{
	/**
	 * .
	 * setter
	 * \param e episodes
	 */
	this->episodes = e;
}

void Anime::setRating(int r)
{
	/**
	 * .
	 * setter
	 * \param r rating
	 */
	this->rating = r;
}

void Anime::setTitle(std::string t)
{
	/**
	 * .
	 * setter
	 * \param t title
	 */
	this->title = t;
}

void Anime::setStudio(std::string s)
{
	/**
	 * .
	 * setter
	 * \param s studio
	 */
	this->studio = s;
}

std::ostream& operator<<(std::ostream& stream, Anime N)
{
	/**
	 * .
	 * stream overload operator
	 * \param stream the stream
	 * \param N anime we work with
	 * \return the modified stream
	 */
	stream << "Anime with title: " << N.title << " from studio: " << N.studio << " with " << N.episodes << " episodes and with a rating of " << N.rating<<'\n';
	return stream;
}