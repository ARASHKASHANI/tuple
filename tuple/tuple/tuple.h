#pragma once

#include <memory>
#include<vector>
#include<string>
#include<typeinfo>

#include "bad_cast_exception.h"


namespace experimental {

	

	class Wrapper_base {

	public:


		virtual const type_info& type() = 0;
		virtual ~Wrapper_base() = default;


	};

	template <typename T>
	class  Wrapper : public  Wrapper_base {

	public:

		const type_info& type() {

			return typeid(t_);

		}

		T getValue() { return t_; }

		~Wrapper() override = default;

		Wrapper(const T& t) : t_(t) {}



	private:


		T t_;



	};



	// the Object class is storage for any type of variable


	class Object {


	public:

		template <typename T>
		T cast() {



			if (dynamic_cast<Wrapper<T>*> (up.get())) {


				T p = dynamic_cast<Wrapper<T>*> (up.get())->getValue();

				return p;

			}

			else {
				bad_cast_exception e("bad_cast_exception thrown ...");
				throw e;
			}


		}


		Wrapper_base* ptr() { return up.get(); }

		const type_info& type() {

			return up.get()->type();

		}


		template <typename T>
		Object& operator=(T& t) {

			up = std::make_unique<Wrapper<T>>(t);

			// aux for debugging
			//  std::cout << "operator=(T& t) is called ..." << endl;



			return *this;
		}

		template <typename T>
		Object& operator=(T&& t) {

			up = std::make_unique<Wrapper<T>>(t);

			// aux for debugging
			//  std::cout << "operator=(T&& t) is called ..." << endl;



			return *this;
		}

		template <typename T>
		Object(T& t) {

			up = std::make_unique<Wrapper<T>>(t);

			// aux for debugging
			//  std::cout << "Container (T& t) is called ..." << endl;

		}

		template <typename T>
		Object(T&& t) {

			up = std::make_unique<Wrapper<T>>(t);

			// aux for debugging
			//  std::cout << "Container (T&& t) is called ..." << endl;

		}





	private:



		std::unique_ptr<Wrapper_base> up;





	};



	// a hetrogenous vector that can hold any type of variable regardless of its type
	typedef std::vector<Object> het_vector;

	class Tuple {
	private:
		std::vector<Object> vc;

	public:



		template <typename T>
		void push_back(T& t) {

			vc.push_back(Object(t));

		}

		template <typename T>
		void push_back(T&& t) {

			vc.push_back(Object(t));

		}

		Object& operator[](unsigned int index) {

			return vc[index];

		}



	};


}

