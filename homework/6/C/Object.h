#pragma once
#include <list>
#include <iostream>
#include <memory>

#include "CustomClass.h"



class Object {
private:
	class Content {
	public:
		virtual void output(std::ostream& out){ //virtual function for output
			std::cout << "the operator is not supported for this type." << std::endl;
		}
		virtual void operator +=(int s){}
		virtual void operator +=(std::string s){}
		virtual Object& operator[](int s){}
	};
	std::shared_ptr<Content> pt;
public:
	class IntContent: public Content {
	private:
		int x;
	public:
		IntContent(int _x): x(_x) {}
		void output(std::ostream& out){ //???
			out << x;
		}
		void operator +=(int s) {
			x += s;
		}
	};

	class StringContent: public Content {
	private:
		std::string x;
	public:
		StringContent(std::string _x): x(_x) {}
		void output(std::ostream& out){  //???
			out << x;
		}
		void operator +=(std::string s) {
			x += s;
		}
	};

	// The following codes are not working
	class VectorContent: public Content {
	private:
		std::vector<Object> x; //Object is not defined???
	public:
		VectorContent(const std::vector<Object>& _x): x(_x) {}
		Object& operator[](int s) {
			return x[s];
		}
	};

	class CustomContent: public Content {
	private:
		CustomClass x;
	public:
		CustomContent(const CustomClass& _x): x(_x) {}
	};

	Object() {}
	Object(int x) {
		std::shared_ptr<Content> tmp(new IntContent(x));
		pt = tmp; // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string &x) {
		std::shared_ptr<Content> tmp(new StringContent(x));
		pt = tmp;
	}
	//The following codes are not working
	Object(const std::vector<Object> &x) {
		std::shared_ptr<Content> tmp(new VectorContent(x));
		pt = tmp;
	}
	Object(const CustomClass &x) {
		std::shared_ptr<Content> tmp(new CustomContent(x));
		pt = tmp;
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt -> output(out);
		return out;
	}

	Object& operator+=(int y) {
		pt -> operator+=(y);
		return *this;
	}
	Object& operator+=(const std::string &y) {
		pt -> operator+=(y);
		return *this;
	}

	Object& operator[] (int s) {
		return pt -> operator[](s);
	}
	//need more operators......
};
