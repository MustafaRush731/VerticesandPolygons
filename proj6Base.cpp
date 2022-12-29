/*
 *  TODO:  Add file name, author, date, and purpose
 */
 #include <cstdlib>
 #include <iostream>
 #include "vertex.h"
 #include "vertexSet.h"
 #include "polygon.h"
 
 using namespace std;	// Debatable, but easier for now.
 
 int main( int argc, char ** argv ) {
   VertexSet* setVertex = new VertexSet();
   
   double X = 0;
   double Y = 0;
   double Z = 0;
   double luminosity = 0;
   
   while(1){
     //user enters 4 inputs for the vertices
     cin >> X >> Y >> Z >> luminosity;
     //if the user enters a negative luminosity then break from while loop
     if(luminosity < 0 ){
       break;
     }
     // vertex instance that takes the users input as the constructor
     Vertex vertex1(X,Y,Z,luminosity);
     //if adding the vertex to the array was successful then continue
     if(setVertex->addVertex(vertex1) == true){
       #ifdef DEBUG
       cout << "Succesfully added to VertexSet" << endl; 
       #endif
       //else print a error message 
       }else{
       break;
       }
     }
   setVertex->printAll(cout);
   
   //here we are simply printing out the stats without the vertices
   int id = 0;
   int counter = 0;
   int nAllocated = 100;
   //create an allocated array
   Polygon* polygons = new Polygon[nAllocated];
   Vertex* p = NULL;
   while(1){
     cin >> id;
     p = setVertex->getVertexByID(id);
     //if user enteres a id thats not in the set then return null if null check wether the polygons has any nVertices if not break from the loop
     if(p == NULL){
       if(polygons[counter].results() == 0){
         break;
       }
       //counter for certain polygon
       counter++;
       continue;
     }
     //if true print message
     if(polygons[counter].addVertex(*p) == true){
       #ifdef DEBUG
       cout << "succesfully added to Polygons set" << endl;
       #endif
     }else{
       #ifdef DEBUG
       cout << "unsuccesfully added to Polygon" << endl;
       #endif
       }
     }
   cout << endl;
   cout << "Luminosity and Lower and Upper bounds" << endl;
   cout << endl;
   // print bounds of polygon based on counter 
   for(int i = 0; i < counter; i++){
     cout << endl;
     cout << "polygon " << i << endl;
     polygons[i].printAll(cout);
     }
   cout << endl;
   
   double X_2 = 0;
   double Y_2 = 0;
   double Z_2 = 0;
   double luminosity_2 = 0;
   while(1){
     //similar to what we did above but reading in a second set of values for a new vertex
     cin >> X_2 >> Y_2 >> Z_2 >> luminosity_2;
     if(luminosity_2 < 0 ){
       break;
     }
      // vertex instance that takes the users input as the constructor
     Vertex vertex2(X_2,Y_2,Z_2,luminosity_2);
     //if the intersection was successful then print that the cordinated are intersecting
     if(setVertex->intersect(vertex2) == true){
       cout << "This coordinte intersects with the set" << endl;
     }else{
       cout << "This coordinate does not intersect with the set" << endl;
       }
     //check weather the vertex created is coplaner with our current plane
     for(int i = 0; i < counter; i++){
       if(polygons[i].isCoplanar(vertex2) == true){
         cout << "Considered a coplanar with Polygon " << i << endl;
       }else{
         cout << "Not a coplanar with Polygon " << i << endl;
       }
     }
  }
	return 0;
  	
 } // main
 
