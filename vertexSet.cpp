/*
 * TODO: Add file name, author, date, purpose
 */

#include "vertexSet.h"

using namespace std; // Debatable, but easier for now.

/*  Constructors initialize class variables, many to zero.
	VertexSet constructors need to set nAllocated according
	to the initial size of the dynamic array of Vertex pointers,
	and then use new to dynamically allocate an array of that
	size for vertices.  Note that vertices is of type Vertex **,
	i.e. an array of ( pointers to Vertex objects. )  The actual
	vertices will be dynamically allocated later by addVertex.
	( It wouldn't hurt to set all the pointers to NULL initially. )
*/

// No-argument constructor.  Set allocated to 10 by default
VertexSet::VertexSet( ) {
 this-> nAllocated = 10;
  vertices = new Vertex*[nAllocated];
  for(int i = 0; i < this->nAllocated; i++){
    this->vertices[i] = NULL;
  }
  this->nVertices = 0;
} // Constructor ( )

// Constructor with an argument. 
// Set nAllocated to the value of the passed-in argument
VertexSet::VertexSet( int initialCapacity) {
  this-> nAllocated = initialCapacity;
  vertices = new Vertex*[nAllocated];
  for(int i = 0; i < this->nAllocated; i++){
    this->vertices[i] = NULL;
  }
  this->nVertices = 0;
  
} // Constructor( int )

// Destructor needs to free all associated dynamic memory
// This includes all the dynamically allocated Vertices
// AND the dynamically allocated array holding them.
VertexSet::~VertexSet( ) {
  if(this->nVertices > 0){
    for(int i = 0; this->nVertices; i++){
      delete this->vertices[i];
    }
  }
delete[] this->vertices;
} // Destructor

// This looks like a getter, but it could also count vertices instead
int VertexSet::getNumberOfVertices( ) const {
return nVertices;
} // getNumberOfVertices

// Add a vertex to the set.  Create a new Vertex and pass it along.
bool VertexSet::addVertex( const Vertex & vertex ) {
	Vertex *pTemp = new Vertex(vertex);
  if (!pTemp){return false;}
  return addVertex(pTemp);

	/*  TODO: 
		1. Dynamically allocate a new Vertex, using the copy constructor.
		   Return false if new fails.
		2. Pass the pointer to addVertex( Vertex * vertexPtr );
		3. Return the value received in step 2.
	*/
} // addVertex( const Vertex & vertex )


// Add a vertex to the set.  Allocate new memory as needed.
// Returns true if successful, false otherwise
bool VertexSet::addVertex(  Vertex * vertexPtr ) {
  
	/*  TODO: 
		1. Grow the dynamic array if necessary
		2. Add the Vertex pointer to the array, and update counters,
		   luminosity, and upper and lower bounds
		( For step 1, Check the return values from new before using.
		  If new returns NULL, then return false and don't continue. )
		4. If all goes well, return true.
	*/
  if(this->nVertices == 0){
    this->luminosity = vertexPtr->getLuminosity();
    }
  if(nAllocated <= nVertices){
    Vertex **pTemp2 = vertices;
    vertices = new Vertex*[2*this->nAllocated];
    for(int i = 0; i<nAllocated; i++){
      this->vertices[i] = pTemp2[i];
    }
    delete[] pTemp2;
    pTemp2 = NULL;
    nAllocated = 2*nAllocated;
  }
  this->vertices[this->nVertices]= vertexPtr;
  this->nVertices++;

  this->luminosity = (this->luminosity*(this->nVertices-1) + vertexPtr->getLuminosity())/this->nVertices;
  //set max values to the first value from the vertices
  double maxX = vertices[0]->getX();
  double maxY = vertices[0]->getY();
  double maxZ = vertices[0]->getZ();
  //loop through the current vertices and see weather the max values for each coordinate is greater then or equall to the prev value entered
  for(int i = 0; i < nVertices; i++){
    if(maxX <= vertices[i]->getX()){
    maxX = vertices[i]->getX();
    this->upperBounds[0] = maxX;
  }if(maxY <= vertices[i]->getY()){
    maxY = vertices[i]->getY();
    this->upperBounds[1] = maxY;  
  }if(maxZ <= vertices[i]->getZ()){
    maxZ = vertices[i]->getZ();
    this->upperBounds[2] = maxZ;
    }
  }

  //set max values to the first value from the vertices
  double minX = vertices[0]->getX();
  double minY = vertices[0]->getY();
  double minZ = vertices[0]->getZ();
  //loop through the current vertices and see weather the max values for each coordinate is greater then or equall to the prev value entered
  for(int i = 0; i < nVertices; i++){
  if(minX >= vertices[i]->getX()){
    minX = vertices[i]->getX();
    this->lowerBounds[0] = minX;
  }if(minY >= vertices[i]->getY()){
    minY = vertices[i]->getY();
    this->lowerBounds[1] = minY;  
  }if(minZ >= vertices[i]->getZ()){
    minZ = vertices[i]->getZ();
    this->lowerBounds[2] = minZ;
    }
  }
  
  if(vertices != NULL){
    return true;
  }
  return false;
} // addVertex( Vertex * vertexPtr )

// Return true if there is an intersection, false otherwise
bool VertexSet::intersect( const Vertex & vertex ) const {
    Vertex pTemp2 = Vertex(vertex);
  if(pTemp2.getX() >= this->lowerBounds[0] && pTemp2.getX() <= this->upperBounds[0]){
    if(pTemp2.getY() >= this->lowerBounds[1] && pTemp2.getY() <= this->upperBounds[1]){
      if(pTemp2.getZ() >= this->lowerBounds[2] && pTemp2.getZ() <= this->upperBounds[2]){
        return true;
      }
    }
  }
	return false;  // TODO:  Replace this line with code that checks.
} // intersect

// The following function "prints" to outStream all the information about
// a VertexSet, except the actual vertices themselves.
void VertexSet::printStats( ostream & outStream ) const {
  //print the info
	outStream << "This vertex set has " << nVertices << " stored out of " << nAllocated << " available.\n";
  outStream << "the average Luminosity for this set is " << this->luminosity << endl;
  outStream << "This vertexSet upper and lower bounds for X are " << this->upperBounds[0]  << "  " << this->lowerBounds[0] << endl;
  outStream << "This vertexSet upper and lower bounds for Y are " << this->upperBounds[1]  << "  " << this->lowerBounds[1] << endl;
  outStream << "This vertexSet upper and lower bounds for Z are " << this->upperBounds[2]  << "  " << this->lowerBounds[2] << endl;
	
	return;

} // printStats

// The following function "prints" to outStream all the information about
// a VertexSet, INCLUDING ALL VERTICES, regardless of their ID
void VertexSet::printAll( ostream & outStream ) const {
	
	printStats( outStream ); // First call the other function for basics
  cout << endl;
  outStream << "The vertices in the VertexSet are" << endl;
  //loops through the vertex set and prints each coordinate
  for(int i = 0; i < nVertices; i++){
    outStream << vertices[i]->getX() << " " << vertices[i]->getY() << " " << vertices[i]->getZ() << " " << vertices[i]->getLuminosity() << endl;
  }
	//TODO:  Loop through vertices and print using: outStream << * vertices[ ] 
	
	return;

} // printStats

// Return the address of the point with the given ID, or NULL otherwise
Vertex * VertexSet::getVertexByID( int id ) const {
  if(id < 0){
    return NULL;
  }
  for(int i = 0; i < nVertices; i++){
    //if the id entered is equall to the ID within that specific vertice ID then return the address of the vertices
    if(this->vertices[i]->getID() == id){
      return this->vertices[i];
      }
    }
	return NULL; // TODO:  Replace this line with code to find the Vertex *

} // getVertexByID


