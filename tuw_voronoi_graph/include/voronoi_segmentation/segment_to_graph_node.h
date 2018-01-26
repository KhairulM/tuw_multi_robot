/*
 * Copyright (c) 2017, <copyright holder> <email>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY <copyright holder> <email> ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> <email> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef SEGMENT_TO_GRAPH_NODE_H
#define SEGMENT_TO_GRAPH_NODE_H

#include <ros/ros.h>
#include <memory>
#include <tuw_multi_robot_msgs/Vertex.h>
#include <tuw_multi_robot_msgs/VoronoiGraph.h>
#include <geometry_msgs/Point.h>

#include <eigen3/Eigen/Dense>

struct PathSeg
{
    Eigen::Vector2d start;
    Eigen::Vector2d end;
    float width;
    PathSeg(Eigen::Vector2d _s, Eigen::Vector2d _e, double _w) : start(_s), end(_e), width(_w)  {  }
};

class SegmentToGraphNode
{
    public:     SegmentToGraphNode(ros::NodeHandle &n);

    public:     void Publish();

    public:     ros::NodeHandle             n_;      ///< Node handler to the root node
    public:     ros::NodeHandle             n_param_;///< Node handler to the current node
    public:     std::unique_ptr<ros::Rate>      rate_;

// ROS Publishers
    private:    ros::Publisher               pubSegments_;


    private:    std::string             segment_file_;
    private:    std::string             segment_topic_;
    private:    double                  path_length_;

    private:    tuw_multi_robot_msgs::VoronoiGraph current_graph_;

    private:    void readSegments();
    private:    std::vector<int> findNeighbors(std::vector<PathSeg> &_graph, Eigen::Vector2d _point, int _segment);
};

#endif // PLANNER_NODE_H
