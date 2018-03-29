//
// Created by jonas on 29/03/2018.
//

#ifndef CALPROJECT2017_RELATION_H
#define CALPROJECT2017_RELATION_H

/**
 * Relation-Class that represents the relation of the roads with the nodes.
 */
class Relation{
    /**
     * Private attribute that saves the id of the road.
     */
    unsigned long long int roadID;
    /**
     *  Private attribute that saves the id of the first node of the road.
     */
    unsigned long long int node1ID;
    /**
     * Private attribute that saves the id of the second node of the road.
     */
    unsigned long long int node2ID;
public:
    /**
     * Constructor of the class.
     */
    Relation(unsigned long long int roadID,unsigned long long int node1ID,unsigned long long int node2ID);
    /**
     * Getter that returns the id of the road.
     * @return roadID.
     */
    unsigned long long int getRoadID();
    /**
     * Getter that returns the id of the first node.
     * @return node1ID.
     */
    unsigned long long int getNode1ID();
    /**
     * Getter that returns the id of the second node.
     * @return node2ID.
     */
    unsigned long long int getNode2ID();
};



#endif //CALPROJECT2017_RELATION_H
