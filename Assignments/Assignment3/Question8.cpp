#include <iostream>
#include <queue>

using namespace std; 

void move_to_rear(queue que)
{
   if(!empty(que)) // if queue isnt empty
   {
       int temp = que.front(); // the first element becomes FIRST
       que.pop();
       que.push(temp); 
   }
}
