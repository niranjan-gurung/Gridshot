#pragma once

struct Stats 
{
	int score, hitCounter, missCounter, accuracy;
	
	Stats() 
		: score(0), hitCounter(0), missCounter(0), accuracy(100) 
	{}
};