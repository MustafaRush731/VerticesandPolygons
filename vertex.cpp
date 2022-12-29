/*
 * TODO: Add file name, author, date, purpose
 */

#include "vertex.h"

/*
 * Vertex implementation
 */
 
// Initialize the static int class variable.
int Vertex::nextID = 0;
 
// TODO:  Set initial values in constructor.  Make getters functional

// Two constructors
// Note that the first one  must assign a new unique value to ID, 
// making use of static int nextID

Vertex::Vertex( double X,  double Y,  double Z,  double luminosity ) {
	
	this->coordinates[0] = X;
  this->coordinates[1] = Y;
  this->coordinates[2] = Z;
	this->luminosity = luminosity;
  this -> ID = nextID;
  nextID += 1;
	// "this->luminosity" refers to class variable, "= luminosity" param
	// "this->" is not needed if class variable name and param name are different.
}

/*  The copy constructor should copy all the data of the input vertex,
	including the ID.  That has potential problems, but is better than
	the alternative ( creating a new unique ID for the copy ) for our
	purposes at the moment.
	
	Note:  This is an important function, because the system uses it 
	every time a Vertex is passed by value, by copying the Vertex
	onto the call stack.  Strange things break until you write this method.	
*/

Vertex::Vertex( const Vertex & vertex ) {
	
	luminosity = vertex.luminosity;	// Sample.  Copy from vertex to class variable
  this->coordinates[0] = vertex.coordinates[0];
  this->coordinates[1] = vertex.coordinates[1];
  this->coordinates[2] = vertex.coordinates[2];
  this->ID = vertex.ID;
  
}

// Destructor.  ( This method has nothing to do right now. )

Vertex::~Vertex( ) {
	
}

// Getters return class values

int Vertex::getID( ) const {
  return this->ID;
}

double Vertex::getX( ) const {
  return this->coordinates[0];
}

double Vertex::getY( ) const {
  return this->coordinates[1];
}

double Vertex::getZ( ) const {
  return this->coordinates[2];
}

double Vertex::getLuminosity( ) const {
  return this->luminosity;
}

 
 // The following method allows code like this, where v is a Vertex:
 //			cout << "Vertex v = " << v << endl;
 // Note the code sends output to the variable "out", not cout
 // Also note that since this method is not a member of the Vertex class,
 // it must call the appropriate getters to get the values to be printed.
 
 ostream & operator << ( ostream & out, const Vertex & vertex ) {
 	
 	out << "( X: " << vertex.getX( );
 	out << " Y: " << vertex.getY( );
  out << " Z: " << vertex.getZ( );
  out << " Luminosity: " << vertex.getLuminosity( );
 	out << " )";
 	
 	return out; 	
 	
 } // operator << ( ostream &, Vertex )