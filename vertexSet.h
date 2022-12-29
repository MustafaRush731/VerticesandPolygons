/*
 * TODO: Add file name, author, date, purpose
 */

#ifndef _VERTEXSET_H
#define _VERTEXSET_H

#include <cstdlib>
#include <iostream>
#include "vertex.h"

using namespace std;  // Debatable.  Easier for now.

class VertexSet {
	
	// Protected data memebers are accessible to descendants
	
	protected: 
	    Vertex ** vertices; // Dynamic array of POINTERS TO Vertex objects
	    int nVertices;
	    
	// Private data memebers - Descendants don't need access to these?
	
	private: 
	    int nAllocated;
	    double luminosity;
	    double lowerBounds[ 3 ];
	    double upperBounds[ 3 ];
	    
	// Public methods
	
	public: 
	    
	    // Two constructors and one destructor
		VertexSet( );
		VertexSet( int initialCapacity );
		virtual ~VertexSet( );
		
		int getNumberOfVertices( ) const;
		virtual bool addVertex( const Vertex & vertex ); // Child can override this
		virtual bool addVertex( Vertex * vertexPtr ); // Child can override this
		Vertex * getVertexByID( int id ) const;
		bool intersect( const Vertex & vertex ) const;
		void printStats( ostream & out ) const;
		void printAll( ostream & out ) const;
};

#endif //_VERTEXSET_H