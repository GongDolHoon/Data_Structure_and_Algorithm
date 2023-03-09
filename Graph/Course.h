#pragma once

#include <string>
#include <vector>

class Course final
{
public:
	Course(const std::string title)
		:mTitle(title)
	{
	}

	Course(const Course& other) = delete;
	Course& operator=(const Course& other ) = delete;

	~Course() = default;

	inline std::string GetTitle() const
	{
		return mTitle;
	}

	inline std::vector<Course*> GetNextCourses() const
	{
		return mNextCourses;
	}

	inline void AddNext(Course* course)
	{
		mNextCourses.push_back(course);
	}

private:
	const std::string mTitle;
	std::vector<Course*> mNextCourses;
};