#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

#include "Course.h"

std::vector<Course*> CreateCourseGraph();
std::list<Course*> SortTopologically(std::vector<Course*>&);
void TopologicalSortRecursive(Course*, std::unordered_set<Course*>&, std::list<Course*>&);

int main()
{
	std::vector<Course*> courses = CreateCourseGraph();

	std::list<Course*> sortedCourses = SortTopologically(courses);

	for (Course* course : sortedCourses)
	{
		std::cout << course->GetTitle() << std::endl;
	}
}

std::vector<Course*> CreateCourseGraph()
{
	Course* comp0000 = new Course("0000: Intro to Programming for Novices and Hobbyists (C#)");
	Course* comp1500 = new Course("1500: Intro to Professional Programming with C#");
	Course* comp1000 = new Course("1000: Math for Software Engineers");
	Course* comp1600 = new Course("1600: Visual Programming with C#");
	Course* comp2200 = new Course("2200: Unmanaged Programming with C");
	Course* comp2500 = new Course("2500: Object Oriented Programming and Design with Java");
	Course* comp4700 = new Course("4700: Database Programming with C#");
	Course* comp2300 = new Course("2300: Assembly");
	Course* comp3200 = new Course("3200: Unmanaged Programming with C++");
	Course* comp3500 = new Course("3500: Algorithm & Data Structure with Java");
	Course* comp3000 = new Course("3000: Computer Architecture (C or Assembly)");
	Course* comp4000 = new Course("4000: Operating Systems (C)");
	Course* comp4100 = new Course("4100: Data Comm (C or C++)");

	comp0000->AddNext(comp1500);

	comp1500->AddNext(comp1000);
	comp1500->AddNext(comp1600);
	comp1500->AddNext(comp2200);
	comp1500->AddNext(comp2500);

	comp1000->AddNext(comp1600);
	comp1000->AddNext(comp2200);
	comp1000->AddNext(comp2500);

	comp1600->AddNext(comp4700);

	comp2200->AddNext(comp2300);
	comp2200->AddNext(comp3200);
	comp2200->AddNext(comp3000);

	comp2500->AddNext(comp4700);
	comp2500->AddNext(comp3200);
	comp2500->AddNext(comp3500);

	comp2300->AddNext(comp3000);
	
	comp3200->AddNext(comp4000);
	comp3200->AddNext(comp4100);

	comp3000->AddNext(comp4000);

	std::vector<Course*> courses;

	courses.push_back(comp0000);
	courses.push_back(comp1000);
	courses.push_back(comp1500);
	courses.push_back(comp1600);
	courses.push_back(comp2200);
	courses.push_back(comp2300);
	courses.push_back(comp2500);
	courses.push_back(comp3000);
	courses.push_back(comp3200);
	courses.push_back(comp3500);
	courses.push_back(comp4000);
	courses.push_back(comp4100);
	courses.push_back(comp4700);

	return courses;
}

std::list<Course*> SortTopologically(std::vector<Course*>& courses)
{
	std::unordered_set<Course*> discovered;
	std::list<Course*> sortedList;

	for (Course* course : courses)
	{
		if (discovered.contains(course))
		{
			continue;
		}

		TopologicalSortRecursive(course, discovered, sortedList);
	}

	return sortedList;
}

void TopologicalSortRecursive(Course* course, std::unordered_set<Course*>& discovered, std::list<Course*>& list)
{
	discovered.insert(course);

	for (Course* nextCourse : course->GetNextCourses()) 
	{
		if (discovered.contains(nextCourse))
		{
			continue;
		}

		TopologicalSortRecursive(nextCourse, discovered, list);
	}

	list.push_front(course);
}