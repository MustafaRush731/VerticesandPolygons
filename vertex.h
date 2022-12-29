/*
 * TODO: Add file name, author, date, purpose
 */


#ifndef _VERTEX_H
#define _VERTEX_H

#include <cstdlib>
#include <iostream>

using namespace std; // Debatable, but easier for now.

class Vertex {
	
	/* Private data members */
		
	private: 
	    int ID;
	    static int nextID;
	    double coordinates[ 3 ];
	    double luminosity;
	    
	/* Public methods */
	
	public: 
	    
		// Two constructors and one destructor
		Vertex( double X, double Y, double Z, double luminosity );
		Vertex( const Vertex & vertex ); // Copy constructor
		~Vertex( );
		
		// Getters
		int getID( ) const;    
		double getX( ) const;    
		double getY( ) const;    
		double getZ( ) const;    
		double getLuminosity( ) const;

};

 
// Function prototype.  The following is not a class method
ostream & operator << ( ostream & out, const Vertex & vertex );


#endif //_VERTEX_H