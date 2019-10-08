#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int radius = 50; radius < 300; radius += 20) {

		ofPushMatrix();
		ofRotateY(300 - radius * 0.5 + ofGetFrameNum());

		vector<glm::vec3> vertices_1, vertices_2;
		for (int deg = 90; deg < 360 + 90; deg += 60) {

			vertices_1.push_back(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0));
			vertices_2.push_back(glm::vec3((radius - 10) * cos(deg * DEG_TO_RAD), (radius - 10) * sin(deg * DEG_TO_RAD), 0));
		}

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		ofVertices(vertices_1);
		ofNextContour(true);
		ofVertices(vertices_2);
		ofEndShape(true);

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		ofVertices(vertices_1);
		ofNextContour(true);
		ofVertices(vertices_2);
		ofEndShape(true);

		ofPopMatrix();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}