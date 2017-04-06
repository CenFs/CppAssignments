#ifndef QUEUE_HH
#define QUEUE_HH

#include <string>
#include <memory>

using namespace std;

class Queue {
 public:
   Queue();

   void add_to_end(const string& new_patient_name);
   bool remove_from_front(string& removed_patient_name);
   bool is_empty() const;
   void print() const;

 private:
   struct Cell {
      string patient_name;
      shared_ptr<Cell> next_ptr;
   };

   shared_ptr<Cell> first_ptr_;
   shared_ptr<Cell> last_ptr_;
};

#endif
