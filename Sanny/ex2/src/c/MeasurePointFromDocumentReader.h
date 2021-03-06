/*
 * DocumentToFileWriter.h
 *
 *  Created on: 01.05.2017
 *      Author: alesan
 */

#ifndef C_MEASUREPOINTFROMDOCUMENTREADER_H_
#define C_MEASUREPOINTFROMDOCUMENTREADER_H_

#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#include "MeasurePoint.h"

using namespace xercesc;
using namespace std;

/** Go through a DOM and find all MeasuremePoints */
class MeasurePointFromDocumentReader {
private:
	DOMDocument* document;
	istringstream strin;
	vector<MeasurePoint*> measurePoints;

	XMLCh* NODE_gasDay;

	XMLCh* ATTR_date;
	XMLCh* ATTR_gasDayStartHourInUTC;
	XMLCh* ATTR_gasDayLengthInHours;
	XMLCh* ATTR_hour;
	XMLCh* ATTR_value;

	void writeMeasuredToFile(DOMNode* measuredNode);
	void readBoundaryNode(DOMNode* boundaryNode, /**tm*/ string date, int dayLength, int startHour);
	void readTimeNode(DOMNode* timeNode, /**tm*/ string date, int dayLength, int startHour);
	void readAmountOfPowerNode(DOMNode* amountOfPowerNode, /**tm*/ string date, int dayLength, int startHour);
	void readGasDayNode(DOMNode* gasDayNode);
	string getNodeName(DOMNode* node);
	/**tm*/ string getNodeValueAsString(DOMNode* node);
	int getNodeValueAsInt(DOMNode* node);
	double getNodeValueAsDouble(DOMNode* node);
	void initNodes();
	void initAttributes();

public:
	/** Getter for all read MeasurePoints */
	vector<MeasurePoint*> getMeasurePoints();
	/** main -> read all MeasurePoints by going through the parsed xml via DOM using xercesc*/
	void readMeasurepoints();
	/** Constructor */
	MeasurePointFromDocumentReader(DOMDocument* document);
	/** Deconstructor */
	virtual ~MeasurePointFromDocumentReader();
};

#endif /* C_MEASUREPOINTFROMDOCUMENTREADER_H_ */
