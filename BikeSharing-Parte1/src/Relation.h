#pragma once

/**
 * Relation-Class that represents the relation of the roads with the nodes.
 */
class Relation{
    /**
     * Private attribute that saves the id of the street.
     */
    unsigned long long int streetID;
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
    Relation(unsigned long long int streetID,unsigned long long int node1ID,unsigned long long int node2ID);
    /**
     * Getter that returns the id of the street.
     * @return roadID.
     */
    unsigned long long int getStreetID();
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

