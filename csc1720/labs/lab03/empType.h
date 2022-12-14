/* 
   Author:
   Date:
   Class: CSC-1720
   Code location:
   
   About: 
*/
#ifndef EMP_TYPE
#define EMP_TYPE

#include<iostream>
#include<iomanip>

using namespace std;

class empType {
   private:
      string name;
      int age;
      double salary;
		int id;
   public:
		//compares the objects id that is exeecuting the function to the passed in objects id
   	bool compareTo(const empType& otherEmp) const;
		empType(int iId, string iName, int iAge, double iSalary);
		empType();
	   /* Three set methods for the empType class. 
       * pre-condition: each set method receives the data via a parameter
       * post-condition: the data is stored in the associate private instance
       *                 variable.
       */
      void setName(string name_in);
      void setAge(int age_in);
      void setSalary(double salary_in);
		void setId(int id_in);
      /* Three get methods for the empType class. 
       * pre-condition: each set method receives the data via a parameter
       * post-condition: the data is stored in the associate private instance
       *                 variable.
       */
      string getName(void) const;
      int getAge(void) const;
      double getSalary(void) const;
		int getId(void) const;
};
#endif
