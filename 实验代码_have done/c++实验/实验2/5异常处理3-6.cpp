#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <stdexcept>

using std::cin;
using std::setprecision;
using std::cout;
using std::string;
using std::endl;
using std::streamsize;
using std::domain_error;

int main(int argc, char const *argv[]) 
{
  // ask for and read the student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // ask for the homework grades
  cout << "Enter all your homework grades, "
       "followed by end-of-file: ";

  // the number and sum of grades read so far
  int count = 0;
  double sum = 0;

  // a variable into which to read
  double x;

  // invariant:
  //     we have read `count' grades so far, and
  //     `sum' is the sum of the first `count' grades
  while (cin >> x) 
  {
    ++count;
    sum += x;
  }

  try
  {
    if(count==0) throw domain_error("");

    double homework_grade = sum / count ;

    // write the result
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * homework_grade
         << setprecision(prec) << endl;
  }
  catch(domain_error)
  {
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final 
         << setprecision(prec) << endl;
  }
  return 0;
}