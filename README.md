# CPP AP Project

***
## Part 1 
This part compair two vector class. They are using two methods for making the vector class.One use single pointer (T*) and the other use double pointer. I test both of them and the result are this.


You can observe that VectorPointer class is faster. I think that because of lower size of pointer instead of the whole object.My every test case are about 100 MB. they began with 100 * 1mb object  and end with 2* 50MB object. In every test I use insert at index 0 (because it cause run a for loop for whole class!) and remove the the index 0 after that. I did it 10 times for every case and avrage the time took every try. The graphs are the resultes of this tests.

***
## Part 2

