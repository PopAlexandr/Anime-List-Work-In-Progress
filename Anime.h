#pragma once
#include <cstring>
#include <string>
class Anime {
public:
	Anime();
	Anime(int episodes, std::string title, std::string studio, int rating);
	Anime(const Anime& other);
	int getEpisodes()const;
	int getRating() const;
	std::string getTitle();
	std::string getStudio();
	void setEpisodes(int e);
	void setRating(int r);
	void setTitle(std::string t);
	void setStudio(std::string s);
	friend std::ostream& operator<<(std::ostream& stream, Anime N);

protected:
	int episodes;
	std::string title;
	std::string studio;
	int rating;

};