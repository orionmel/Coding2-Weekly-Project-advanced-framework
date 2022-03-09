#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ////////////////////////////////⚠️⚠️⚠️⚠️隧道⚠️⚠️⚠️⚠️///////////////////////////////////
    ofSetLineWidth(1.5);
    ofEnableDepthTest();
    
    /////////////////////////////🌟🌟🌟🌟🌟不变的基本声音设置🌟🌟🌟🌟🌟///////////////////////////////////////
    //初始化绘图变量
    for (int i = 0; i < ofGetWidth(); ++i) {
        waveform[i] = 0;
    }
    waveIndex = 0;
    
    // Maximilian 的声音
    int sampleRate = 44100; /* 采样率 */
    int bufferSize= 512; /* 缓冲区大小。您必须使用 audioOut 方法中的 for 循环用声音填充此缓冲区 */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    //设置
    myClock.setTempo(120);
    myClock.setTicksPerBeat(4);
    
    // 设置声音
    ofSoundStreamSettings settings;
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    /////////////////////////////🌟🌟🌟🌟🌟不变的基本声音设置🌟🌟🌟🌟🌟///////////////////////////////////////
   
    

    /////🌹加载声音
    mySample.load(ofToDataPath("33.wav"));

    
    
    /////////////////////////////🌟🌟🌟🌟🌟设置gui🌟🌟🌟🌟🌟///////////////////////////////////////
    gui.setup();
    
    //vec4调节颜色
    gui.add(vec4Slider.setup("vec4 slider", ofVec4f(0, 0, 0, 0), ofVec4f(0, 0, 0, 0), ofVec4f(255, 255, 255, 255)));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(ofGetMouseY()*ofRandom(200), ofGetMouseX(), 250);
  
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i <1000; i++) {
        ofSetColor(ofRandom(100)*ofGetMouseX(), 200, 300);
            ofDrawLine(ofGetMouseX()+sin( TWO_PI / 1000* i * (ofGetMouseX()/50))*cos(TWO_PI / 1000* i * (ofGetMouseY()/78))*200+20 ,

                       ofGetMouseY()+sin( TWO_PI / 1000* i * (ofGetMouseY()/50))*sin(TWO_PI / 1000* i * (ofGetMouseY()/50))*200+20,ofGetMouseX(),ofGetMouseY());
        }
    
    
    
    
    for (int i = 0; i < 256; i++) {
     
            ofPoint point(ofMap(ofNoise(ofRandom(100) + ofGetFrameNum() * 0.005), 0, 1, ofGetWidth() * -0.3, ofGetWidth() * 1.3), ofMap(ofNoise(ofRandom(100) + ofGetFrameNum() * 0.001), 0, 1, ofGetHeight() * -0.3, ofGetHeight() * 1.3));
            float radius = ofRandom(0, 10);
            ofColor circle_color;
//            circle_color.setHsb(ofRandom(255), 255, 255 * ofNoise(point.x * 0.05, point.y * 0.05, ofGetFrameNum() * 0.001));
            ofSetColor(ofRandom(250),ofRandom(250),250);
     
            ofDrawCircle(point, radius);
        }
    
    
    
    
    
    
    
    ////////////////////////////////⚠️⚠️⚠️⚠️隧道⚠️⚠️⚠️⚠️///////////////////////////////////
    this->cam.begin();

    
        ofRotateX(0);
    //摄像机的角度
    cam.setPosition(0,0, 0); // 为我们的easyCam 3D查看器设置初始位置，从后面看
    cam.orbit(0,0, 0);
     
        int v_span = 1;
        int u_span = 60;
     
        ofMesh face, line;
        line.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
    
  
     
        for (int z = -1200; z <= 0; z += 100) {
     
            auto R = ofMap(z, -1200, 0, 125, 200);
     
            for (int v = 0; v <= 360; v += v_span) {
     
                int u_start = ofMap(ofNoise(200 * cos(v * DEG_TO_RAD) * 0.0025, 200 * sin(v * DEG_TO_RAD) * 0.0025, z * 0.005 + ofGetFrameNum() * 0.005), 0, 1, -360, 360);
                int next_u = ofMap(ofNoise(200 * cos((v + v_span) * DEG_TO_RAD) * 0.0025, 200 * sin((v + v_span) * DEG_TO_RAD) * 0.0025, z * 0.005 + ofGetFrameNum() * 0.005), 0, 1, -360, 360);
                for (int u = u_start; u < u_start + 360; u += u_span) {
     
                    face.addVertex(this->make_point(R, 50, u, v) + glm::vec3(0, 0, z));
                    face.addVertex(this->make_point(R, 50, u + u_span, v) + glm::vec3(0, 0, z));
                    face.addVertex(this->make_point(R, 50, next_u + u_span, v + v_span) + glm::vec3(0, 0, z));
                    face.addVertex(this->make_point(R, 50, next_u, v + v_span) + glm::vec3(0, 0, z));
     
                    line.addVertex(this->make_point(R, 50, u, v) + glm::vec3(0, 0, z));
                    line.addVertex(this->make_point(R, 50, u + u_span, v) + glm::vec3(0, 0, z));
                    line.addVertex(this->make_point(R, 50, next_u + u_span, v + v_span) + glm::vec3(0, 0, z));
                    line.addVertex(this->make_point(R, 50, next_u, v + v_span) + glm::vec3(0, 0, z));
     
                    ofColor color = ofColor(255);
                    if ((u - u_start) % (u_span * 2) || true) {
     
                        for (int i = 1; i <= 4; i++) {
     
                            //color.setHsb(ofMap(ofNoise(face.getVertex(face.getNumVertices() - i) * 0.003), 0, 1, 128, 255), 200, 255);
                            color.setHsb(ofMap(ofNoise(200 * cos(v * DEG_TO_RAD) * 0.0025, 200 * sin(v * DEG_TO_RAD) * 0.0025, z * 0.005 + ofGetFrameNum() * 0.005), 0, 1, 128, 255), 100, 255);
                            face.addColor(color);
                        }
                    }
                    else {
     
                        face.addColor(color);
                        face.addColor(color);
                        face.addColor(color);
                        face.addColor(color);
                    }
     
                    face.addIndex(face.getNumVertices() - 1); face.addIndex(face.getNumVertices() - 2); face.addIndex(face.getNumVertices() - 3);
                    face.addIndex(face.getNumVertices() - 1); face.addIndex(face.getNumVertices() - 3); face.addIndex(face.getNumVertices() - 4);
     
                    line.addIndex(line.getNumVertices() - 1); line.addIndex(line.getNumVertices() - 4);
                    line.addIndex(line.getNumVertices() - 2); line.addIndex(line.getNumVertices() - 3);
     
                    next_u += u_span;
                }
            }
        }
     
        face.drawFaces();
        line.drawWireframe();
     
        this->cam.end();
    
  
    

}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer& input){
    /////////////////////////////🌟🌟🌟🌟🌟声音基本设置🌟🌟🌟🌟🌟///////////////////////////////////////
    
    std::size_t nChannels = input.getNumChannels();
    for (size_t i = 0; i < input.getNumFrames(); i++)
    {
       
    }
}
//--------------------------------------------------------------
void ofApp::audioOut(ofSoundBuffer& output){
    
    //设置时间
    int time;
    time = ofGetElapsedTimef();
    
    /////////////////////////////🌟🌟🌟🌟🌟声音基本设置🌟🌟🌟🌟🌟///////////////////////////////////////
    //获取声音渠道
    std::size_t outChannels = output.getNumChannels();
    
    
    for (int i = 0; i < output.getNumFrames(); ++i){
        
        ///❤️////////////////////////

        //通过鼠标变化clock
        if (myClock.tick && time % 2 == 1) {
            myFreq +=3*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        }else {
            myFreq -=3*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        }


        output[i * outChannels] = myOsc1.sinewave(myFreq + abs(myOsc2.sinewave(43.066) * myOsc3.coswave(myFreq)*0.043))*(ofGetMouseX()+ofGetMouseY())/(ofGetWidth()+ofGetHeight());
        
        output[i * outChannels + 1] = output[i * outChannels];


        float myOut = mySample.play();
        
        /////////////////////////////🌟🌟🌟🌟🌟声音基本设置🌟🌟🌟🌟🌟///////////////////////////////////////
        //保留这些值，以便 draw 方法可以绘制它们
        waveform[waveIndex] =  output[i * outChannels];
        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        } else {
            waveIndex = 0;
        }
    }
  
}

glm::vec3 ofApp::make_point(float R, float r, float u, float v) {
 
    // 数学デッサン教室 描いて楽しむ数学たち　P.31
 
    u *= DEG_TO_RAD;
    v *= DEG_TO_RAD;
 
    auto x = (R + r * cos(u)) * cos(v);
    auto y = (R + r * cos(u)) * sin(v);
    auto z = r * sin(u);
 
    return glm::vec3(x, y, z);
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
