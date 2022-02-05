#pragma once

#include <iostream>
#include <cstring>

struct Meme
{
	std::string template_name;
	std::string text;
	size_t likes_count = 0;
};

void print_meme(Meme meme);
Meme generate_meme();