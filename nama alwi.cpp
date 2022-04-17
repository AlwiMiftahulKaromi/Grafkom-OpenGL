#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int pencet = -1;

    static void error_callback(int error, const char* description) {
      fputs(description, stderr);
    }
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
    }
void Lingkaran2(double poX, double poY, double width, double height, int Start, int End, float R, float G, float B){
    glBegin(GL_POLYGON);
    glColor3ub(R,G,B);
    for (int i=Start; i <= End; i++)
    {
        float rad = i*3.14/180;
        glVertex2f(poX +cos(rad)*width/2 ,poY +sin(rad)*height/2 );
    }
    glEnd();
}

void lingkaran(int r, int g, int b,double x, double y, double sudut1, double sudut2,double jari){
    glBegin(GL_POLYGON);
    glColor3ub(r,g,b);
    glVertex2d(x,y);
    for(int i=sudut1; i<=sudut2 ; i++){
        double rad = 3.14*i/180;
        glVertex2d(sin(rad)*jari+(x),cos(rad)*jari+(y));
    }
    glEnd();
}

//void Isal(){
//    lingkaran(255, 255, 255, 817, 64, 180, 360, 50);
//}

void A(){
    glBegin(GL_QUADS); //kotak kiri
    glColor3ub(93, 98, 250);
    glVertex2d(140.15, 261.99);
    glVertex2d(180.34, 278.63);
    glVertex2d(127.64, 405.87);
    glVertex2d(87.45, 389.22);
    glEnd();

    glBegin(GL_TRIANGLES); //segitiga atas
    glColor3ub(118, 45, 255);
    glVertex2d(139.97, 261.75);
    glVertex2d(188.03, 261.75);
    glVertex2d(164, 318);
    glEnd();

    Lingkaran2(87.5, 389.25, 87, 87, -67.53, 112.47, 50, 202, 246); //set lingkaran bawah kiri

    glBegin(GL_QUADS); //kotak bawah
    glColor3ub(103, 77, 254);
    glVertex2d(141.5, 362.25);
    glVertex2d(200.75, 362.25);
    glVertex2d(200.75, 405.75);
    glVertex2d(141.5, 405.75);
    glEnd();

    Lingkaran2(142.25, 362.25, 87, 87, 0, 180, 63, 173, 248); //set lingkaran bawah

    glBegin(GL_QUADS); //kotak kanan
    glColor3ub(65, 164, 249);
    glVertex2d(164, 318.15);
    glVertex2d(204.19, 301.5);
    glVertex2d(240.57, 389.33);
    glVertex2d(200.38, 405.98);
    glEnd();

    Lingkaran2(204.5, 302.25, 87, 87, 67.53, 247.53, 48, 213, 245); //set lingkaran atas kanan

    Lingkaran2(240.5, 389.25, 87, 87, 67.64, 247.64, 87, 117, 251); //set lingkaran bawah kanan

}

void L(){
    glBegin(GL_QUADS); //kotak kiri
    glColor3ub(65, 164, 249);
    glVertex2d(269.5, 305.5);
    glVertex2d(313, 305.5);
    glVertex2d(313, 389.5);
    glVertex2d(269.5, 389.5);
    glEnd();

    glBegin(GL_QUADS); //kotak bawah
    glColor3ub(103, 77, 254);
    glVertex2d(269.5, 389.5);
    glVertex2d(346, 389.5);
    glVertex2d(346, 433);
    glVertex2d(269.5, 433);
    glEnd();

    Lingkaran2(313, 305.5, 87, 87, 90, 270, 87, 117, 251); //set lingkaran atas

    Lingkaran2(269.5, 389.5, 87, 87, -90, 90, 50, 202, 246); //set lingkaran bawah kiri

    Lingkaran2(346, 433, 87, 87, -180, 0, 63, 173, 248); //set lingkaran bawah kanan
}

void W(){
    glBegin(GL_QUADS); //kotak kiri1
    glColor3ub(62, 173, 247);
    glVertex2d(340.55, 278.35);
    glVertex2d(380.74, 261.71);
    glVertex2d(428.03, 375.89);
    glVertex2d(387.85, 392.54);
    glEnd();

    glBegin(GL_TRIANGLES); //segitiga atas kiri
    glColor3ub(83, 120, 252);
    glVertex2d(333.62, 261.75);
    glVertex2d(380.38, 261.75);
    glVertex2d(357, 318);
    glEnd();

    Lingkaran2(397.5, 302.25, 87, 87, 67.53, 247.53, 62, 173, 247); //set lingkaran kiri atas

    glBegin(GL_QUADS); //kotak kiri2
    glColor3ub(65, 164, 249);
    glVertex2d(452.82, 316.82);
    glVertex2d(493.01, 333.47);
    glVertex2d(451.94, 432.63);
    glVertex2d(411.75, 415.99);
    glEnd();

    glBegin(GL_TRIANGLES); //segitiga kiri bawah
    glColor3ub(99, 87, 255);
    glVertex2d(404.87, 432.75);
    glVertex2d(451.63, 432.75);
    glVertex2d(428.25, 376.5);
    glEnd();

    Lingkaran2(387.75, 392.25, 87, 87, -112.53, 67.47, 50, 202, 246); //set lingkaran kiri bawah


    glBegin(GL_QUADS); //kotak kanan1
    glColor3ub(62, 173, 247);
    glVertex2d(435.8, 278.35);
    glVertex2d(475.99, 261.71);
    glVertex2d(523.28, 375.89);
    glVertex2d(483.1, 392.54);
    glEnd();

    glBegin(GL_TRIANGLES); //segitiga atas kanan
    glColor3ub(83, 120, 252);
    glVertex2d(428.87, 261.75);
    glVertex2d(475.63, 261.75);
    glVertex2d(452.25, 318);
    glEnd();

    Lingkaran2(397.5, 302.25, 87, 87, 67.53, 247.53, 62, 173, 247); //set lingkaran kanan atas

    glBegin(GL_QUADS); //kotak kanan2
    glColor3ub(65, 164, 249);
    glVertex2d(559.88, 288.31);
    glVertex2d(600.07, 304.96);
    glVertex2d(547.19, 432.63);
    glVertex2d(507, 415.99);
    glEnd();

    glBegin(GL_TRIANGLES); //segitiga kanan bawah
    glColor3ub(99, 87, 255);
    glVertex2d(500.12, 432.75);
    glVertex2d(546.88, 432.75);
    glVertex2d(523.5, 376.5);
    glEnd();

    Lingkaran2(483, 392.25, 87, 87, -112.53, 67.47, 50, 202, 246); //set lingkaran kanan bawah


    Lingkaran2(600, 305.25, 87, 87, 112.53, 292.53, 48, 213, 245); //set lingkaran ujung kanan
}

void I(){
    glBegin(GL_QUADS); //kotak kiri
    glColor3ub(65, 164, 249);
    glVertex2d(614.5, 305.5);
    glVertex2d(658, 305.5);
    glVertex2d(658, 389.5);
    glVertex2d(614.5, 389.5);
    glEnd();

    Lingkaran2(658, 305.5, 87, 87, 90, 270, 87, 117, 251); //set lingkaran atas

    Lingkaran2(614.5, 389.5, 87, 87, -90, 90, 50, 202, 246); //set lingkaran bawah
}

void M(){
    glBegin(GL_QUADS); //kotak kiri
    glColor3ub(65, 164, 249);
    glVertex2d(745.5, 262);
    glVertex2d(789, 262);
    glVertex2d(789, 390);
    glVertex2d(745.5, 390);
    glEnd();

    Lingkaran2(789, 305.5, 87, 87, 90, 270, 87, 117, 251); //lingkaran kiri atas1

    Lingkaran2(745.5, 389.5, 87, 87, -90, 90, 50, 202, 246); //set lingkaran kiri bawah

    //Lingkaran2(700, 200, 87, 87, 350, 380, 50, 202, 246); //NYOBA

    glBegin(GL_QUADS); //kotak tengah1
    glColor3ub(62, 173, 247);
    glVertex2d(788.93, 305.48);
    glVertex2d(829.12, 288.83);
    glVertex2d(847.25, 332.6);
    glVertex2d(807.06, 349.25);
    glEnd();

    Lingkaran2(789, 305.5, 87, 87, -112.5, 67.5, 87, 117, 251); //set lingkaran kiri atas2

    glBegin(GL_QUADS); //kotak tengah2
    glColor3ub(62, 173, 247);
    glVertex2d(865.19, 288.12);
    glVertex2d(905.38, 304.77);
    glVertex2d(887.2, 348.65);
    glVertex2d(847.01, 332.01);
    glEnd();

    Lingkaran2(847, 332, 87, 87, -22.5, 157.5, 87, 117, 251); //set lingkaran tengah 1

    Lingkaran2(847, 332, 87, 87, -67.5, 112.5, 87, 117, 251); //set lingkaran tengah 2

    glBegin(GL_QUADS); //kotak kanan
    glColor3ub(65, 164, 249);
    glVertex2d(905, 262);
    glVertex2d(948.5, 262);
    glVertex2d(948.5, 390);
    glVertex2d(905, 390);
    glEnd();

    Lingkaran2(905, 305.5, 87, 87, -157.5, 22.5, 87, 117, 251); //set lingkaran kanan atas 1

    Lingkaran2(905, 305.5, 87, 87, -90, 90, 87, 117, 251); //set lingkaran kanan atas 2

    Lingkaran2(948.5, 389.5, 87, 87, 90, 270, 50, 202, 246); //set lingkaran kanan bawah
}

void K(){
    glBegin(GL_QUADS); //kotak miring bawah
    glColor3ub(65, 164, 249);
    glVertex2d(1073.01, 351.82);
    glVertex2d(1108.64, 326.87);
    glVertex2d(1154.45, 392.29);
    glVertex2d(1118.82, 417.24);
    glEnd();

    glBegin(GL_QUADS); //kotak miring atas
    glColor3ub(87, 117, 251);
    glVertex2d(1116.7, 277.5);
    glVertex2d(1150.02, 305.46);
    glVertex2d(1079.16, 389.91);
    glVertex2d(1045.84, 361.95);
    glEnd();

    glBegin(GL_QUADS); //kotakkiri
    glColor3ub(65, 164, 249);
    glVertex2d(1036, 305);
    glVertex2d(1079.5, 305);
    glVertex2d(1079.5, 433);
    glVertex2d(1036, 433);
    glEnd();

    Lingkaran2(1036, 305.5, 87, 87, -90, 90, 87, 117, 251); //set lingkaran kiri atas

    Lingkaran2(1079.5, 389.5, 87, 87, 90, 270, 50, 202, 246); //set lingkaran kiri bawah 1

    Lingkaran2(1079.5, 389.5, 87, 87, 130, 310, 50, 202, 246); //set lingkaran kiri bawah 2

    Lingkaran2(1150, 305.5, 87, 87, 130, 310, 50, 202, 246); //set lingkaran ujung kanan atas

    Lingkaran2(1152.5, 389.5, 87, 87, 55, 235, 87, 117, 251); //set lingkaran ujung kanan bawah
}

void Bintang1(){
    glPushMatrix();
        glTranslated(981, 413, 0); // buat koordinat yaxis, xaxis pusat rotate
        glRotatef(((float)glfwGetTime())*100,0.0f,0.0f,1.0f);
        glTranslated(-981 , -413, 0); // mines yaxis, xaxis pusat rotate


    glBegin(GL_LINE_LOOP);
    glColor3ub(50, 202, 246);

    glVertex2d(981, 388);
    glVertex2d(986.61, 405.27);

    glVertex2d(1004.78, 405.27);
    glVertex2d(990.08, 415.95);

    glVertex2d(995.69, 433.23);
    glVertex2d(981, 422.55);

    glVertex2d(966.31, 433.23);
    glVertex2d(971.92, 415.95);

    glVertex2d(957.225, 405.27);
    glVertex2d(975.39, 405.27);
    glEnd();
    glPopMatrix();
}

void Bintang2(){
    glPushMatrix();
        glTranslated(1210, 413, 0); // buat koordinat yaxis, xaxis pusat rotate
        glRotatef(((float)glfwGetTime())*-100,0.0f,0.0f,1.0f);
        glTranslated(-1210 , -413, 0); // mines yaxis, xaxis pusat rotate

    glBegin(GL_LINE_LOOP);
    glColor3ub(50, 202, 246);

    glVertex2d(1210, 388);
    glVertex2d(1215.61, 405.27);

    glVertex2d(1233.78, 405.27);
    glVertex2d(1219.08, 415.95);

    glVertex2d(1224.69, 433.23);
    glVertex2d(1210, 422.55);

    glVertex2d(1195.31, 433.23);
    glVertex2d(1200.92, 415.95);

    glVertex2d(1186.22, 405.27);
    glVertex2d(1204.39, 405.27);
    glEnd();
    glPopMatrix();
}

class BintangKursor{
public:
    double x = 0;
    double y = 0;
    void BintangTengah(){
        glPushMatrix();
        glTranslated(x, y, 0); // buat koordinat yaxis, xaxis pusat rotate
        glRotatef(((float)glfwGetTime())*-100,0.0f,0.0f,1.0f);
        glTranslated(-x , -y, 0); // mines yaxis, xaxis pusat rotate

        glBegin(GL_POLYGON);
        if(pencet == -1){
            glColor3ub(50, 202, 246);
        }
        else {
            glColor3ub(87, 117, 251);
        }
        glVertex2d(0 + x, -60 + y);
        glVertex2d(-35.27 + x, 48.54 + y);
        glVertex2d(0 + x, 22.92 + y);
        glVertex2d(35.27 + x, 48.54 + y);
        glEnd();

        glBegin(GL_TRIANGLES);
        if(pencet == -1){
            glColor3ub(50, 202, 246);
        }
        else {
            glColor3ub(87, 117, 251);
        }
        glVertex2d(-57.06 + x, -18.54 + y);
        glVertex2d(57.06 + x, -18.54 + y);
        glVertex2d(0 + x, 22.92 + y);
        glEnd();
        glPopMatrix();
    }
    void doIfGeser(double xpos, double ypos){
    /*    if(isRectangleSelected(xpos, ypos) == GL_TRUE)
            red = blue = 0;
        else
            red = blue = 255; */
        x=xpos;
        y=ypos;
    glPushMatrix();
        glTranslated(x, y, 0); // buat koordinat yaxis, xaxis pusat rotate
        glRotatef(((float)glfwGetTime())*100,0.0f,0.0f,1.0f);
        glTranslated(-x , -y, 0); // mines yaxis, xaxis pusat rotate
        BintangTengah(); // objek nya
    glPopMatrix();
    }
};
BintangKursor a;

class TombolKursor{
    public:
    void Tombol(){
            if(pencet == -1){
                Lingkaran2(640, 557, 128, 128, 0, 360, 170, 236, 255); //set lingkaran kiri atas
            }
            else{
                Lingkaran2(640, 557, 128, 128, 0, 360, 0, 198, 255); //set lingkaran kiri atas
            }
        }

        int isCursorInside(double x_cursor, double y_cursor) {
        double d, dx, dy;
        dx = x_cursor - 640;
        dy = y_cursor - 557;
        d = sqrt(dx*dx + dy*dy);
        if (d < 64) {
    //      stopButton();
          return 1;
        }
        else
          return 0;
    }
    void onButtonPressed(int button, int action, double x_cursor, double y_cursor) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
          int cursor_active = isCursorInside(x_cursor, y_cursor);
          if (cursor_active) {
            pencet *= -1;

          }
        }
    }
};
TombolKursor b;

void GarisGaris(){
    glBegin(GL_LINES);
    glColor3ub(50, 202, 246);
    glVertex2d(115, 97);
    glVertex2d(1168, 97);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(50, 202, 246);
    glVertex2d(115, 170);
    glVertex2d(1168, 170);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(50, 202, 246);
    glVertex2d(432, 521);
    glVertex2d(115, 521);
    glVertex2d(115, 592);
    glVertex2d(432, 592);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3ub(50, 202, 246);
    glVertex2d(837, 521);
    glVertex2d(1154, 521);
    glVertex2d(1154, 592);
    glVertex2d(837, 592);
    glEnd();
}
// Callback untuk merespons perubahan posisi kursor
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    a.doIfGeser(xpos, ypos);

}
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    double posx, posy;
    glfwGetCursorPos(window, &posx, &posy);
    b.onButtonPressed(button, action, posx, posy);
}

void setup_viewport(GLFWwindow* window)
{
    // setting viewports size, projection etc
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1280, 720, 0, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display()
    {
    if (pencet == -1){
        glClearColor(11.0/255.0f, 8.0/255.0f, 51.0/255.0f, 1.0f); //warna background
    }
    else{
        glClearColor(170.0/255.0f, 236.0/255.0f, 255.0/255.0f, 1.0f); //warna background
    }

    glClear(GL_COLOR_BUFFER_BIT);
    double stop = glfwGetTime();
    glPushMatrix();
        glTranslated(640, 360,0);
        if (stop <= 10) glScalef(stop*0.1,stop*0.1,0);
        glTranslated(-640, -360,0);
    A();
    L();
    W();
    I();
    M();
    K();
    Bintang1();
    Bintang2();

    glPopMatrix();
    GarisGaris();
    b.Tombol();
    a.BintangTengah();

    glFlush();
    //Isal();
    }
int main(void) {
        //Window
        GLFWwindow* window;
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())exit(EXIT_FAILURE);
        window = glfwCreateWindow(1280, 720, "ALWI M. K.", NULL, NULL);

        if (!window){
          glfwTerminate();
          exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1);
        //register callback
        glfwSetCursorPosCallback(window, cursor_position_callback);
        glfwSetMouseButtonCallback(window, mouse_button_callback);
        glfwSetKeyCallback(window, key_callback);

        while (!glfwWindowShouldClose(window)){
          int width, height;
          setup_viewport(window);
            display();
          glfwGetFramebufferSize(window, &width, &height);
          glViewport(0, 0, width, height);
          //fungsi untuk menampilkan objek
          glfwSwapBuffers(window);
          glfwPollEvents();
        }


    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
