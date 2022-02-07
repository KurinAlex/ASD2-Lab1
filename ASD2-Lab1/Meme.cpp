#include "Meme.h"


void Meme::print()
{
	std::cout << ">> Template name: " << template_name <<
		"\n>> Text: " << text <<
		"\n>> Likes count: " << likes_count << "\n";
}

std::string template_names[] = { "Doge","Dratuti","Gachi","Shrek","Jacque Fresco","Demotivator" };
size_t template_names_size = size(template_names);

std::string texts[] = { "This is so sad", "What...How?","LOL" };
size_t texts_size = size(texts);

Meme generate_meme()
{
	return { template_names[rand() % template_names_size], texts[rand() % texts_size], (size_t)rand() % 20000 };
}