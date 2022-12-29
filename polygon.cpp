/**
 * TODO:  Add filename, author, date, purpose
 */

#include "polygon.h"

Polygon::Polygon() {}

Polygon::Polygon(int initialCapacity) {}

Polygon::~Polygon() {}

/*  The Polygon::addVertex method first ascertains whether it is acceptable
	to add the given vertex to the polygon.  Reasons for rejecting the vertex
	would be if the ID of the vertex already exists in the Polygon, or if the 
	vertex is not coplanar with the vertices already in the Polygon.  (Use the 
	getVertexByID( ) and isCoplanar( ) methods to check these two conditions.)
	If Polygon::addVertex finds the vertex unacceptable, it should return false;
	
	If Polygon::addVertex finds the vertex acceptable, then it should pass the 
	vertex to VertexSet::addVertex( Vertex ) to do the actual adding of the 
	vertex.
	
	If nVertices becomes 3 as a result of adding this vertex, then calcNormal( ) 
	should be called to calculate the normal to the polygon.
*/

void Polygon::PolygonResults( ){
  if(nVertices == 3){
    cout << "the normal of the Polygon is " << endl;
    cout << normal[0] << " " << normal[1] << " " << normal[2] << endl; 
    }
}

//add Vertex Checks weather the temp passed through is a mullptr if so add then if the Vertices is equall to three then get the calcNormal
bool Polygon::addVertex(const Vertex & vertex) {
  Vertex * temp = getVertexByID(vertex.getID());
    if (temp == nullptr) {
      VertexSet::addVertex(vertex);
      if(nVertices==3){
        this->calcNormal();
        }
      if (isCoplanar(vertex) == true) {
        return true;
        }
      }
  return false;
}

bool Polygon::addVertex(Vertex * vertexPtr) {
  // This method should first do the aforementioned checks for validity.
  // If it fails, return false
  // Otherwise, pass vertexPtr to VertexSet::addVertex( Vertex * vertexPtr )
  Vertex * temp = getVertexByID(vertexPtr->getID());
    if (temp == nullptr) {
      VertexSet::addVertex(vertexPtr);
      if(nVertices==3){
        this->calcNormal();
        }
      if (isCoplanar(*vertexPtr) == true) {
        return true;
        }
      }
  return false;
}
/*  The isCoplanar method determines if the passed Vertex is coplanar with the 
	existing vertices of the polygon, ( or at least not out of the plane of the 
	existing vertices ), as follows:
	
	1. If nVertices is less than 3, return true.  The point is not out of the 
	   plane.
	2. Otherwise create a vector from the first vertex in the Polygon 
	   ( * vertices[0] ) to the passed vertex.
	3. Then calculate the dot product between the vector created in step 2 and 
	   the normal.
	4. If the absolute value of the dot product is less than some small 
	   tolerance, say 1.0E-6, then return true;  Otherwise return false.
*/

bool Polygon::isCoplanar(const Vertex & vertex) const {
  double vertex1[3];
  //inistialize array
  for(int i = 0; i < 3; i++){
    vertex1[i] = 0;
  }
  double finalValue = 0;
  //anything less then 3 is true
  if (nVertices < 3) {
    return true;
  } else if (nVertices >= 3) {
    //create a vector using the passed vertex and using the beging vertice
    this -> calcVector( * vertices[0], vertex, vertex1);
    finalValue = this -> dot(vertex1, normal);
    //check weather the dot product is leass then a specific value if so return true
    if(abs(finalValue)< 1.0e-6 ){
      return true;
    }
  }
  return false;
}

/*  The normal to the polygon is calculated as the cross product between two 
	vectors, both of which lie in the plane of the Polygon, as follows:
	
	1. Create a vector from * vertices[ 0 ] to * vertices[ 1 ]
	2. Create a second vector from * vertices[ 0 ] to * vertices[ 2 ]
	3. Calculate the cross product of the first vector and the second,
	   and save the result in normal[ ].

*/
void Polygon::calcNormal() {
  double vertex3[3];
  double vertex4[3];
  //inisialize two arrays
  for(int i = 0; i < 3; i++){
    vertex3[i] = 0;
    vertex4[i] = 0; 
  }
  //Create a vector from * vertices[ 0 ] to * vertices[ 1 ]
	//Create a second vector from * vertices[ 0 ] to * vertices[ 2 ]
  this -> calcVector( * vertices[0], * vertices[1], vertex3);
  this -> calcVector( * vertices[0], * vertices[2], vertex4);
  //Calculate the cross product of the first vector and the second, and save the result in normal[ ].
  this -> cross( vertex3, vertex4 , normal);
  #ifdef DEBUG
  cout << "Results 2" << endl; 
  cout << vertex3[0] << endl;
  cout << vertex3[1] << endl;
  cout << vertex3[2] << endl;
  #endif
}

/*  calcVector calculates a vector from vertex 1 to vertex 2, by simply 
	subtracting their components in the X, Y, and Z directions respectively. 
	X = X2 - X1, Y = Y2 - Y1, Z = Z2 - Z1.

*/
void Polygon::calcVector(const Vertex & start,
  const Vertex & finish, double result[3]) const {
  //calcVector calculates a vector from vertex 1 to vertex 2, by simply 
	//subtracting their components in the X, Y, and Z directions respectively. 
	//X = X2 - X1, Y = Y2 - Y1, Z = Z2 - Z1.
  result[0] = finish.getX() - start.getX();
  result[1] = finish.getY() - start.getY();
  result[2] = finish.getZ() - start.getZ();
}

/*  The cross product between two vectors is a third vector, which is 
	perpendicular to the first two and which obeys the "right hand rule".
	The formula for calculating the cross of 
	vec1 = ( X1, Y1, Z1 ) x vec2 = ( X2, Y2, Z2 ) is:
	
	X = Y1 * Z2 - Y2 * Z1
	Y = Z1 * X2 - Z2 * X1
	Z = X1 * Y2 - X2 * Y1
*/

void Polygon::cross(const double vec1[3],
  const double vec2[3], double result[3]) const {
  result[0] = vec1[1] * vec2[2] - vec2[1] * vec1[2];
  result[1] = vec1[2] * vec2[0] - vec2[2] * vec1[0];
  result[2] = vec1[0] * vec2[1] - vec2[0] * vec1[1];
  #ifdef DEBUG
  cout << "Vector 1" << endl;
  cout << vec1[0] << endl;
  cout << vec1[1] << endl; 
  cout << vec1[2] << endl;
  cout << "Vector 2" << endl;
  cout << vec2[0] << endl;
  cout << vec2[1] << endl; 
  cout << vec2[2] << endl; 
  cout << "Cross Product " << endl;
  cout << result[0] << endl;
  cout << result[1] << endl; 
  cout << result[2] << endl;
  #endif
}

/* The dot product of two vectors is simply the sum of the products of their
	components, i.e. X1 * X2 + Y1 * Y2 + Z1 * Z2.  The result will be zero if
	the two vectors are perpendicular to each other.
*/
double Polygon::dot(const double vec1[3],
  const double vec2[3]) const {
  double p = vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
  #ifdef DEBUG
  cout << "Results for vector" << endl;
  cout << vec1[0] << endl;
  cout << vec1[1] << endl;
  cout << vec1[2] << endl;
  cout << "results for normal array" << endl;
  cout << vec2[0] << endl;
  cout << vec2[1] << endl;
  cout << vec2[2] << endl;
  cout << "P results " << endl;
  cout << p << endl;
  #endif
  return p;
}
