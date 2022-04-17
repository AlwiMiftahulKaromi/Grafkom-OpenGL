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

void doIfGeser(double xpos, double ypos){
    /*    if(isRectangleSelected(xpos, ypos) == GL_TRUE)
            red = blue = 0;
        else
            red = blue = 255; */
        double x = 0;
        double y = 0;
        x=xpos;
        y=ypos;
}
class TombolKursor{
    public:
        double x=56, y=56;
        int size = 32;
    void TombolLampu(){
        glLineWidth(3.0f);

        if(pencet == -1){
            glBegin(GL_POLYGON);
            glColor3ub(121, 247, 243);
            glVertex2d(24,24);
            glVertex2d(88,24);
            glVertex2d(88,88);
            glVertex2d(24,88);
            glEnd();
        }
        else{
            glBegin(GL_POLYGON);
            glColor3ub(41, 49, 86);
            glVertex2d(24,24);
            glVertex2d(88,24);
            glVertex2d(88,88);
            glVertex2d(24,88);
            glEnd();
        }
        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        glVertex2d(24,24);
        glVertex2d(88,24);
        glVertex2d(88,88);
        glVertex2d(24,88);
        glEnd();
    }
    GLboolean isRectangleSelected(double xpos, double ypos){
        double left = x - size;
        double right = x + size;
        double top = y + size;
        double bottom = y - size;

        if((xpos > left) && (xpos < right) && (ypos < top) && (ypos > bottom))
            return GL_TRUE;
        else
            return GL_FALSE;
    }
    void onButtonPressed(int button, int action, double x_cursor, double y_cursor) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
          int cursor_active = isRectangleSelected(x_cursor, y_cursor);
          if (cursor_active) {
            pencet *= -1;

          }
        }
    }
};
TombolKursor a;

void Api(){
    double stop = glfwGetTime();
    glPushMatrix();
        glTranslated(223.5, 482, 0);
        if (stop <= 10) glScalef(stop*0.1,stop*0.1,0);
        glTranslated(-223.5, -482, 0);
    //merah
    Lingkaran2(223.5, 514.5, 73, 73, 181, 360, 255, 95, 106);
    glBegin(GL_POLYGON);
    glColor3ub(255, 95, 106);
    glVertex2d(187,513.5);
    glVertex2d(260,513.5);
    glVertex2d(255.5,543);
    glVertex2d(243,570);
    glVertex2d(223.5,595.5);
    glVertex2d(204,570);
    glVertex2d(191.5,543);
    glEnd();
    //oranye
    Lingkaran2(223.5, 509.5, 55, 55, 181, 360, 255, 180, 100);
    glBegin(GL_POLYGON);
    glColor3ub(255, 180, 100);
    glVertex2d(196,509);
    glVertex2d(251,509);
    glVertex2d(247.5,531);
    glVertex2d(238,551.5);
    glVertex2d(223.5,570.5);
    glVertex2d(208.5,551.5);
    glVertex2d(199.5,531);
    glEnd();
    //kuning
    Lingkaran2(223.5, 505, 37, 37, 181, 360, 255, 255, 102);
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 102);
    glVertex2d(205,504.5);
    glVertex2d(242,504.5);
    glVertex2d(239,518);
    glVertex2d(233,531);
    glVertex2d(223.5,543);
    glVertex2d(214,531);
    glVertex2d(208,518);
    glEnd();

    glPopMatrix();
}

void Api123(){
    glPushMatrix();
    glTranslatef(8, 0, 0);
    Api();
    glTranslatef(199, 121, 0);
    Api();
    glTranslatef(144, -83, 0);
    Api();

    glPopMatrix();
}

void Teras(){
    glLineWidth(2.0f);
    glBegin(GL_QUADS); //pinggir depan
    glColor3ub(14, 27, 97);
    glVertex2d(482.5,629.5);
    glVertex2d(629.5,544.5);
    glVertex2d(629.5,557.5);
    glVertex2d(482.5,642.5);
    glEnd();

    glBegin(GL_QUADS); //pinggir kanan atas
    glColor3ub(14, 27, 97);
    glVertex2d(369,553);
    glVertex2d(423.5,584.5);
    glVertex2d(423.5,597.5);
    glVertex2d(369,566);
    glEnd();

    glBegin(GL_QUADS); //pinggir kanan bawah
    glColor3ub(14, 27, 97);
    glVertex2d(409,587.5);
    glVertex2d(482.5,629.5);
    glVertex2d(482.5,642.5);
    glVertex2d(409,600.5);
    glEnd();

    glBegin(GL_QUADS); //pinggir bangunan
    glColor3ub(33, 42, 121);
    glVertex2d(182,445);
    glVertex2d(369,553);
    glVertex2d(369,566);
    glVertex2d(182,458);
    glEnd();

    glBegin(GL_QUADS); //teras bawah
    glColor3ub(17, 80, 124);
    glVertex2d(423.5,595.5);
    glVertex2d(570.5,510.5);
    glVertex2d(629.5,544.5);
    glVertex2d(482.5,629.5);
    glEnd();

    glBegin(GL_QUADS); //pink bawah
    glColor3ub(221, 37, 129);
    glVertex2d(423.5,584.5);
    glVertex2d(570.5,499.5);
    glVertex2d(570.5,510.5);
    glVertex2d(423.5,595.5);
    glEnd();

    glBegin(GL_QUADS); //pink atas
    glColor3ub(241, 36, 139);
    glVertex2d(414,579);
    glVertex2d(561,494);
    glVertex2d(570.5,499.5);
    glVertex2d(423.5,584.5);
    glEnd();

    glBegin(GL_QUADS); //teras atas
    glColor3ub(17, 80, 124);
    glVertex2d(330,530.5);
    glVertex2d(477,445.5);
    glVertex2d(561,494);
    glVertex2d(414,579);
    glEnd();

    //outline
    glBegin(GL_LINE_LOOP); //pinggir depan
    glColor3ub(0, 0, 0);
    glVertex2d(482.5,629.5);
    glVertex2d(629.5,544.5);
    glVertex2d(629.5,557.5);
    glVertex2d(482.5,642.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //pinggir kanan atas
    glColor3ub(0, 0, 0);
    glVertex2d(369,553);
    glVertex2d(423.5,584.5);
    glVertex2d(423.5,595.5);
    glVertex2d(482.5,629.5);
    glVertex2d(482.5,642.5);
    glVertex2d(409,600.5);
    glVertex2d(409,589.5);
    glVertex2d(369,566);
    glEnd();

    glBegin(GL_LINE_LOOP); //pinggir bangunan
    glColor3ub(0, 0, 0);
    glVertex2d(182,445);
    glVertex2d(369,553);
    glVertex2d(369,566);
    glVertex2d(182,458);
    glEnd();

    glBegin(GL_LINE_LOOP); //teras bawah
    glColor3ub(0, 0, 0);
    glVertex2d(423.5,595.5);
    glVertex2d(570.5,510.5);
    glVertex2d(629.5,544.5);
    glVertex2d(482.5,629.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //pink bawah
    glColor3ub(0, 0, 0);
    glVertex2d(423.5,584.5);
    glVertex2d(570.5,499.5);
    glVertex2d(570.5,510.5);
    glVertex2d(423.5,595.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //pink atas
    glColor3ub(0, 0, 0);
    glVertex2d(414,579);
    glVertex2d(561,494);
    glVertex2d(570.5,499.5);
    glVertex2d(423.5,584.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //teras atas
    glColor3ub(0, 0, 0);
    glVertex2d(330,530.5);
    glVertex2d(477,445.5);
    glVertex2d(561,494);
    glVertex2d(414,579);
    glEnd();
}

void AtapKiri(){
    //plank atas kiri
    glBegin(GL_QUADS); //pinggir atas
    glColor3ub(121, 247, 243);
    glVertex2d(468.5,248.5);
    glVertex2d(479,242.5);
    glVertex2d(549,283);
    glVertex2d(538.5,289);
    glEnd();
    glBegin(GL_QUADS); //muka kanan
    glColor3ub(121, 247, 243);
    glVertex2d(468.5,248.5);
    glVertex2d(538.5,289);
    glVertex2d(538.5,324);
    glVertex2d(468.5,283.5);
    glEnd();
    glBegin(GL_QUADS); //muka kiri
    glColor3ub(121, 247, 243);
    glVertex2d(538.5,289);
    glVertex2d(549,283);
    glVertex2d(549,318);
    glVertex2d(538.5,324);
    glEnd();
    //outline plank atas kiri
    glBegin(GL_LINE_LOOP); //pinggir atas
    glColor3ub(0, 0, 0);
    glVertex2d(468.5,248.5);
    glVertex2d(479,242.5);
    glVertex2d(549,283);
    glVertex2d(538.5,289);
    glEnd();
    glBegin(GL_LINE_LOOP); //muka kanan
    glColor3ub(0, 0, 0);
    glVertex2d(468.5,248.5);
    glVertex2d(538.5,289);
    glVertex2d(538.5,324);
    glVertex2d(468.5,283.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //muka kiri
    glColor3ub(0, 0, 0);
    glVertex2d(538.5,289);
    glVertex2d(549,283);
    glVertex2d(549,318);
    glVertex2d(538.5,324);
    glEnd();

    //atap kiri
    glBegin(GL_POLYGON);
    glColor3ub(118, 1, 108);
    glVertex2d(329,154.5);
    glVertex2d(345.5,145);
    glVertex2d(493.5,230.5);
    glVertex2d(477,240);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(118, 1, 108);
    glVertex2d(477,240);
    glVertex2d(493.5,230.5);
    glVertex2d(493.5,234.5);
    glVertex2d(477,244);
    glEnd();
    //outline atap kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(329,154.5);
    glVertex2d(345.5,145);
    glVertex2d(493.5,230.5);
    glVertex2d(477,240);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(477,240);
    glVertex2d(493.5,230.5);
    glVertex2d(493.5,234.5);
    glVertex2d(477,244);
    glEnd();
}

void Bangunan(){
    if(pencet == -1){
        glBegin(GL_QUADS); //tembok kiri
        glColor3ub(255, 198, 248);
        glVertex2d(329,152.5);
        glVertex2d(477,238);
        glVertex2d(477,445.5);
        glVertex2d(329,360);
        glEnd();
    }
    else{
        glBegin(GL_QUADS); //tembok kiri
        glColor3ub(169, 55, 155);
        glVertex2d(329,152.5);
        glVertex2d(477,238);
        glVertex2d(477,445.5);
        glVertex2d(329,360);
        glEnd();
    }
    glBegin(GL_LINE_LOOP); //outline tembok kiri
    glColor3ub(0, 0, 0);
    glVertex2d(329,152.5);
    glVertex2d(477,238);
    glVertex2d(477,445.5);
    glVertex2d(329,360);
    glEnd();

    glBegin(GL_QUADS); //tembok depan
    glColor3ub(17, 80, 124);
    glVertex2d(330,323);
    glVertex2d(477,238);
    glVertex2d(477,445.5);
    glVertex2d(330,530.5);
    glEnd();

    glBegin(GL_QUADS); //ketebalan tembok depan
    glColor3ub(83, 92, 159);
    glVertex2d(324,319.5);
    glVertex2d(465.5,238);
    glVertex2d(477,238);
    glVertex2d(330,323);
    glEnd();

    glBegin(GL_QUADS); //tembok kanan
    glColor3ub(14, 27, 97);
    glVertex2d(182,237.5);
    glVertex2d(330,323);
    glVertex2d(330,530.5);
    glVertex2d(182,445);
    glEnd();

    glBegin(GL_QUADS); //ketebalan tembok kanan
    glColor3ub(207, 131, 198);
    glVertex2d(392.5,189);
    glVertex2d(477,238);
    glVertex2d(465.5,238);
    glVertex2d(381,189);
    glEnd();

    if(pencet == -1){
        glBegin(GL_QUADS); //pintu kanan bawah
        glColor3ub(255, 198, 248);
        glVertex2d(212,292);
        glVertex2d(298.5,342);
        glVertex2d(298.5,386);
        glVertex2d(212,336);
        glEnd();
    }
    else{
        glBegin(GL_QUADS); //pintu kanan bawah
        glColor3ub(169, 55, 155);
        glVertex2d(212,292);
        glVertex2d(298.5,342);
        glVertex2d(298.5,386);
        glVertex2d(212,336);
        glEnd();
    }

    if(pencet == -1){
        glBegin(GL_QUADS); //jendela kanan
        glColor3ub(255, 198, 248);
        glVertex2d(259,436);
        glVertex2d(312.5,467);
        glVertex2d(312.5,497);
        glVertex2d(259,466);
        glEnd();

        glBegin(GL_QUADS); //pintu kanan atas
        glColor3ub(255, 198, 248);
        glVertex2d(204.5,400);
        glVertex2d(249.5,426);
        glVertex2d(249.5,484);
        glVertex2d(204.5,458);
        glEnd();

        glBegin(GL_QUADS); //pintu depan kanan
        glColor3ub(255, 198, 248);
        glVertex2d(346.5,463);
        glVertex2d(370,449.5);
        glVertex2d(370,507.5);
        glVertex2d(346.5,521);
        glEnd();

        glBegin(GL_QUADS); //pintu depan kiri
        glColor3ub(255, 198, 248);
        glVertex2d(436,411.5);
        glVertex2d(462,396.5);
        glVertex2d(462,454.5);
        glVertex2d(436,469.5);
        glEnd();
    }
    else{
        glBegin(GL_QUADS); //jendela kanan
        glColor3ub(169, 55, 155);
        glVertex2d(259,436);
        glVertex2d(312.5,467);
        glVertex2d(312.5,497);
        glVertex2d(259,466);
        glEnd();

        glBegin(GL_QUADS); //pintu kanan atas
        glColor3ub(169, 55, 155);
        glVertex2d(204.5,400);
        glVertex2d(249.5,426);
        glVertex2d(249.5,484);
        glVertex2d(204.5,458);
        glEnd();

        glBegin(GL_QUADS); //pintu depan kanan
        glColor3ub(169, 55, 155);
        glVertex2d(346.5,463);
        glVertex2d(370,449.5);
        glVertex2d(370,507.5);
        glVertex2d(346.5,521);
        glEnd();

        glBegin(GL_QUADS); //pintu depan kiri
        glColor3ub(169, 55, 155);
        glVertex2d(436,411.5);
        glVertex2d(462,396.5);
        glVertex2d(462,454.5);
        glVertex2d(436,469.5);
        glEnd();

    }

    glBegin(GL_QUADS); //ventilasi pintu depan kiri
    glColor3ub(233, 15, 110);
    glVertex2d(436,411.5);
    glVertex2d(462,396.5);
    glVertex2d(462,409);
    glVertex2d(436,424);
    glEnd();

    //outline
    glBegin(GL_LINE_LOOP); //tembok depan
    glColor3ub(0, 0, 0);
    glVertex2d(330,323);
    glVertex2d(477,238);
    glVertex2d(477,445.5);
    glVertex2d(330,530.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //ketebalan tembok depan
    glColor3ub(0, 0, 0);
    glVertex2d(324,319.5);
    glVertex2d(465.5,238);
    glVertex2d(477,238);
    glVertex2d(330,323);
    glEnd();

    glBegin(GL_LINE_LOOP); //tembok kanan
    glColor3ub(0, 0, 0);
    glVertex2d(182,237.5);
    glVertex2d(330,323);
    glVertex2d(330,530.5);
    glVertex2d(182,445);
    glEnd();

    glBegin(GL_LINE_LOOP); //ketebalan tembok kanan
    glColor3ub(0, 0, 0);
    glVertex2d(392.5,189);
    glVertex2d(477,238);
    glVertex2d(465.5,238);
    glVertex2d(381,189);
    glEnd();

    glBegin(GL_LINE_LOOP); //pintu kanan bawah
    glColor3ub(0, 0, 0);
    glVertex2d(212,292);
    glVertex2d(298.5,342);
    glVertex2d(298.5,386);
    glVertex2d(212,336);
    glEnd();

    glBegin(GL_LINE_LOOP); //jendela kanan
    glColor3ub(0, 0, 0);
    glVertex2d(259,436);
    glVertex2d(312.5,467);
    glVertex2d(312.5,497);
    glVertex2d(259,466);
    glEnd();

    glBegin(GL_LINE_LOOP); //pintu kanan atas
    glColor3ub(0, 0, 0);
    glVertex2d(204.5,400);
    glVertex2d(249.5,426);
    glVertex2d(249.5,484);
    glVertex2d(204.5,458);
    glEnd();

    glBegin(GL_LINE_LOOP); //pintu depan kanan
    glColor3ub(0, 0, 0);
    glVertex2d(346.5,463);
    glVertex2d(370,449.5);
    glVertex2d(370,507.5);
    glVertex2d(346.5,521);
    glEnd();

    glBegin(GL_LINE_LOOP); //pintu depan kiri
    glColor3ub(0, 0, 0);
    glVertex2d(436,411.5);
    glVertex2d(462,396.5);
    glVertex2d(462,454.5);
    glVertex2d(436,469.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //ventilasi pintu depan kiri
    glColor3ub(0, 0, 0);
    glVertex2d(436,411.5);
    glVertex2d(462,396.5);
    glVertex2d(462,409);
    glVertex2d(436,424);
    glEnd();
}

void GarisGaris(){
    //garis garis pintu kanan bawah
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2d(205,458);
    glVertex2d(250,432);

    glVertex2d(218.5,430);
    glVertex2d(237.5,419);
    glVertex2d(218.5,427);
    glVertex2d(237.5,416);
    glVertex2d(218.5,424);
    glVertex2d(237.5,413);
    glVertex2d(218.5,421);
    glVertex2d(237.5,410);
    glVertex2d(218.5,418);
    glVertex2d(237.5,407);
    glVertex2d(218.5,415);
    glVertex2d(237.5,404);
    glVertex2d(218.5,412);
    glVertex2d(237.5,401);

    glVertex2d(222.5,427.5);
    glVertex2d(229.5,431.5);
    glVertex2d(229.5,431.5);
    glVertex2d(229.5,436);
    glVertex2d(218.5,438);
    glVertex2d(229.5,431.5);
    glVertex2d(218.5,442.5);
    glVertex2d(229.5,436);

    glVertex2d(218.5,408.5);
    glVertex2d(218.5,450);

    glVertex2d(209.5,425.5);
    glVertex2d(214,423);
    glVertex2d(214,423);
    glVertex2d(214,429);
    glVertex2d(214,429);
    glVertex2d(209.5,431.5);
    glVertex2d(209.5,431.5);
    glVertex2d(209.5,425.5);

    glVertex2d(239.5,420.5);
    glVertex2d(239.5,429);
    glVertex2d(239.5,429);
    glVertex2d(243.5,431.5);
    glVertex2d(243.5,423);
    glVertex2d(243.5,431.5);
    glVertex2d(243.5,431.5);
    glVertex2d(249.5,428);

    //garis garis jendela kanan bawah
    glVertex2d(265,462.5);
    glVertex2d(312.5,490);
    glVertex2d(259,459);
    glVertex2d(265,455.5);
    glVertex2d(259,466);
    glVertex2d(265,462.5);
    glVertex2d(269,465);
    glVertex2d(275,461.5);
    glVertex2d(277,469.5);
    glVertex2d(283,466);

    //garis garis jendela kanan atas
    glVertex2d(212,303);
    glVertex2d(298.5,353);
    glVertex2d(212,336);
    glVertex2d(240.5,319.5);
    glVertex2d(240.5,352.5);
    glVertex2d(269,336);
    glVertex2d(269,369);
    glVertex2d(297.5,352.5);

    //tangga
    glVertex2d(439.5,421.5);
    glVertex2d(446.5,425.5);
    glVertex2d(436,431.5);
    glVertex2d(446.5,425.5);
    glVertex2d(446.5,425.5);
    glVertex2d(446.5,433.5);
    glVertex2d(436,439.5);
    glVertex2d(446.5,433.5);
    glVertex2d(446.5,433.5);
    glVertex2d(453.5,437.5);
    glVertex2d(436,447.5);
    glVertex2d(453.5,437.5);
    glVertex2d(453.5,437.5);
    glVertex2d(453.5,445.5);
    glVertex2d(436,455.5);
    glVertex2d(453.5,445.5);
    glVertex2d(453.5,445.5);
    glVertex2d(462,450.5);

    glEnd();
}

void JendelaDepan(){
    if(pencet == -1){
        glBegin(GL_QUADS); //jendela depan
        glColor3ub(255, 198, 248);
        glVertex2d(342.5,405);
        glVertex2d(365,392);
        glVertex2d(365,414);
        glVertex2d(342.5,427);
        glEnd();
    }
    else{
        glBegin(GL_QUADS); //jendela depan
        glColor3ub(169, 55, 155);
        glVertex2d(342.5,405);
        glVertex2d(365,392);
        glVertex2d(365,414);
        glVertex2d(342.5,427);
        glEnd();
    }
    //outline
    glBegin(GL_LINE_LOOP); //jendela depan
    glColor3ub(0, 0, 0);
    glVertex2d(342.5,405);
    glVertex2d(365,392);
    glVertex2d(365,414);
    glVertex2d(342.5,427);
    glEnd();
}
void JendelaDepan123(){
    JendelaDepan();
    glPushMatrix();
    glTranslatef(22.5, -13, 0);
    JendelaDepan();
    glTranslatef(22.5, -13, 0);
    JendelaDepan();
    glPopMatrix();
}

void AtapKanan(){
    //atap kanan
    glBegin(GL_QUADS); //atas
    glColor3ub(118, 1, 108);
    glVertex2d(165.5,249);
    glVertex2d(182,239.5);
    glVertex2d(330,325);
    glVertex2d(313.5,334.5);
    glEnd();
    glBegin(GL_QUADS); //pinggir kanan
    glColor3ub(118, 1, 108);
    glVertex2d(165.5,249);
    glVertex2d(313.5,334.5);
    glVertex2d(313.5,338.5);
    glVertex2d(165.5,253);
    glEnd();
    glBegin(GL_QUADS); //pinggir depan
    glColor3ub(118, 1, 108);
    glVertex2d(313.5,334.5);
    glVertex2d(330,325);
    glVertex2d(330,329);
    glVertex2d(313.5,338.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(165.5,249);
    glVertex2d(182,239.5);
    glVertex2d(330,325);
    glVertex2d(313.5,334.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir kanan
    glColor3ub(0, 0, 0);
    glVertex2d(165.5,249);
    glVertex2d(313.5,334.5);
    glVertex2d(313.5,338.5);
    glVertex2d(165.5,253);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir depan
    glColor3ub(0, 0, 0);
    glVertex2d(313.5,334.5);
    glVertex2d(330,325);
    glVertex2d(330,329);
    glVertex2d(313.5,338.5);
    glEnd();
}

void Atap(){
    glBegin(GL_QUADS); //atap kiri
    glColor3ub(158, 134, 191);
    glVertex2d(290.5,107);
    glVertex2d(410,176);
    glVertex2d(477,238);
    glVertex2d(329,152.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atap kiri
    glColor3ub(0, 0, 0);
    glVertex2d(290.5,107);
    glVertex2d(410,176);
    glVertex2d(477,238);
    glVertex2d(329,152.5);
    glEnd();


    glBegin(GL_POLYGON); //atap atas
    glColor3ub(11, 13, 62);
    glVertex2d(277.5,83.5);
    glVertex2d(290.5,76);
    glVertex2d(410,145);
    glVertex2d(397,152.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(11, 13, 62);
    glVertex2d(277.5,83.5);
    glVertex2d(397,152.5);
    glVertex2d(397,183.5);
    glVertex2d(277.5,114.5);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(11, 13, 62);
    glVertex2d(397,152.5);
    glVertex2d(410,145);
    glVertex2d(410,176);
    glVertex2d(397,183.5);
    glEnd();

    glBegin(GL_QUADS); //atap kanan
    glColor3ub(11, 13, 62);
    glVertex2d(277.5,114.5);
    glVertex2d(397,183.5);
    glVertex2d(330,323);
    glVertex2d(182,237.5);
    glEnd();

    //outline
    glBegin(GL_LINE_LOOP); //atap atas
    glColor3ub(0, 0, 0);
    glVertex2d(277.5,83.5);
    glVertex2d(290.5,76);
    glVertex2d(410,145);
    glVertex2d(397,152.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(277.5,83.5);
    glVertex2d(397,152.5);
    glVertex2d(397,183.5);
    glVertex2d(277.5,114.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(397,152.5);
    glVertex2d(410,145);
    glVertex2d(410,176);
    glVertex2d(397,183.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //atap kanan
    glColor3ub(0, 0, 0);
    glVertex2d(277.5,114.5);
    glVertex2d(397,183.5);
    glVertex2d(330,323);
    glVertex2d(182,237.5);
    glEnd();
}

void KabelKabel(){
    glBegin(GL_LINE_STRIP); //teras
    glColor3ub(0, 0, 0);
    glVertex2d(369,553);
    glVertex2d(434.5,515.5);
    glVertex2d(479,542);
    glEnd();

    glBegin(GL_LINE_STRIP); //tembok depan1
    glColor3ub(0, 0, 0);
    glVertex2d(482.5,448.5);
    glVertex2d(414.5,488.5);
    glVertex2d(393.5,459);
    glVertex2d(393.5,429);
    glEnd();
    glBegin(GL_LINE_STRIP); //tembok depan2
    glColor3ub(0, 0, 0);
    glVertex2d(393.5,441.5);
    glVertex2d(418,427);
    glVertex2d(418,402);
    glVertex2d(431.5,393.5);
    glVertex2d(431.5,362.5);
    glVertex2d(463.5,343.5);
    glVertex2d(463.5,319.5);
    glEnd();

    glBegin(GL_LINE_STRIP); //tembok kanan
    glColor3ub(0, 0, 0);
    glVertex2d(192.5,451);
    glVertex2d(192.5,419);
    glVertex2d(195.5,408.5);
    glVertex2d(195.5,384);
    glVertex2d(312.5,451.5);
    glVertex2d(312.5,373.5);
    glVertex2d(299,365.5);
    glEnd();
}

void DekorasiTeras(){
    //pembatas jalan
    glBegin(GL_QUADS);
    glColor3ub(106, 138, 157);
    glVertex2d(472.5,522.5);
    glVertex2d(481,517.5);
    glVertex2d(487,521);
    glVertex2d(478.5,526);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(106, 138, 157);
    glVertex2d(472.5,522.5);
    glVertex2d(478.5,526);
    glVertex2d(478.5,545.5);
    glVertex2d(472.5,542);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(106, 138, 157);
    glVertex2d(478.5,526);
    glVertex2d(487,521);
    glVertex2d(487,540.5);
    glVertex2d(478.5,545.5);
    glEnd();

    //kotak lampu
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2d(400.5,532);
    glVertex2d(406.5,528.5);
    glVertex2d(412,531.5);
    glVertex2d(406,535);
    glEnd();

    //lampu
    glBegin(GL_POLYGON);
    glColor3ub(255, 227, 255);
    glVertex2d(550.5,382.5);
    glVertex2d(557.5,386.5);
    glVertex2d(563.5,383);
    glVertex2d(563.5,391);
    glVertex2d(557.5,394.5);
    glVertex2d(550.5,390.5);
    glEnd();
    //outlinelampu
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(550.5,382.5);
    glVertex2d(557.5,386.5);
    glVertex2d(563.5,383);
    glVertex2d(563.5,391);
    glVertex2d(557.5,394.5);
    glVertex2d(550.5,390.5);
    glEnd();
    glBegin(GL_QUADS); //tiang
    glColor3ub(138, 153, 184);
    glVertex2d(531,371.5);
    glVertex2d(535.5,369);
    glVertex2d(535.5,488.5);
    glVertex2d(531,491);
    glEnd();
    glBegin(GL_LINE_LOOP); //outlinetiang
    glColor3ub(0, 0, 0);
    glVertex2d(531,371.5);
    glVertex2d(535.5,369);
    glVertex2d(535.5,488.5);
    glVertex2d(531,491);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(138, 153, 184);
    glVertex2d(526,361.5);
    glVertex2d(532,358);
    glVertex2d(566,377.5);
    glVertex2d(566,384.5);
    glVertex2d(560,388);
    glVertex2d(560,381);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(106, 138, 157);
    glVertex2d(526,361.5);
    glVertex2d(560,381);
    glVertex2d(560,388);
    glVertex2d(531,371.5);
    glVertex2d(531,491);
    glVertex2d(526,488);
    glEnd();
    //tiang
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(526,361.5);
    glVertex2d(532,358);
    glVertex2d(566,377.5);
    glVertex2d(566,384.5);
    glVertex2d(560,388);
    glVertex2d(560,381);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(526,361.5);
    glVertex2d(560,381);
    glVertex2d(560,388);
    glVertex2d(531,371.5);
    glVertex2d(531,491);
    glVertex2d(526,488);
    glEnd();

    //palang
    glBegin(GL_POLYGON);
    glColor3ub(162, 178, 214);
    glVertex2d(502,436.5);
    glVertex2d(506.5,434.5);
    glVertex2d(506.5,458);
    glVertex2d(502,460);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(162, 178, 214);
    glVertex2d(477,417.5);
    glVertex2d(506.5,434.5);
    glVertex2d(502,436.5);
    glVertex2d(477,422);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(105, 181, 211);
    glVertex2d(477,422);
    glVertex2d(502,436.5);
    glVertex2d(502,445);
    glVertex2d(477,430.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(138, 153, 184);
    glVertex2d(496,441.5);
    glVertex2d(502,445);
    glVertex2d(502,460);
    glVertex2d(496,456.5);
    glEnd();

    //outline
    //pembatas jalan
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(472.5,522.5);
    glVertex2d(481,517.5);
    glVertex2d(487,521);
    glVertex2d(478.5,526);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(472.5,522.5);
    glVertex2d(478.5,526);
    glVertex2d(478.5,545.5);
    glVertex2d(472.5,542);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(478.5,526);
    glVertex2d(487,521);
    glVertex2d(487,540.5);
    glVertex2d(478.5,545.5);
    glEnd();

    //palang
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(502,436.5);
    glVertex2d(506.5,434.5);
    glVertex2d(506.5,458);
    glVertex2d(502,460);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(477,417.5);
    glVertex2d(506.5,434.5);
    glVertex2d(502,436.5);
    glVertex2d(477,422);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(477,422);
    glVertex2d(502,436.5);
    glVertex2d(502,445);
    glVertex2d(477,430.5);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(496,441.5);
    glVertex2d(502,445);
    glVertex2d(502,460);
    glVertex2d(496,456.5);
    glEnd();
}

void Trotoar(){
    glBegin(GL_QUADS); //trotoar
    glColor3ub(226, 250, 253);
    glVertex2d(472.5,610.5);
    glVertex2d(509.5,589);
    glVertex2d(522.5,596.5);
    glVertex2d(485.5,618);
    glEnd();

    //outline
    glBegin(GL_LINE_LOOP); //trotoar
    glColor3ub(0, 0, 0);
    glVertex2d(472.5,610.5);
    glVertex2d(509.5,589);
    glVertex2d(522.5,596.5);
    glVertex2d(485.5,618);
    glEnd();
}
void Trotoar12(){
    Trotoar();
    glPushMatrix();
    glTranslatef(-28, -16, 0);
    Trotoar();
    glPopMatrix();
}

void DekorasiTembokDepan(){
    //kotak kabel
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2d(461,330);
    glVertex2d(466,327);
    glVertex2d(466,334);
    glVertex2d(461,337);
    glEnd();

    // plank atas seerlight
    glBegin(GL_QUADS); //penyangga kanan
    glColor3ub(13, 20, 100);
    glVertex2d(339,332);
    glVertex2d(351,339);
    glVertex2d(351,385);
    glVertex2d(339,378);
    glEnd();
    glBegin(GL_QUADS); //penyangga kiri
    glColor3ub(13, 20, 100);
    glVertex2d(469,257);
    glVertex2d(481,264);
    glVertex2d(481,310);
    glVertex2d(469,303);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //penyangga kanan
    glColor3ub(0, 0, 0);
    glVertex2d(339,332);
    glVertex2d(351,339);
    glVertex2d(351,385);
    glVertex2d(339,378);
    glEnd();
    glBegin(GL_LINE_LOOP); //penyangga kiri
    glColor3ub(0, 0, 0);
    glVertex2d(469,257);
    glVertex2d(481,264);
    glVertex2d(481,310);
    glVertex2d(469,303);
    glEnd();

    glBegin(GL_QUADS); //atas
    glColor3ub(105, 141, 165);
    glVertex2d(345,335.5);
    glVertex2d(475,260.5);
    glVertex2d(481,264);
    glVertex2d(351,339);
    glEnd();
    glBegin(GL_QUADS); //samping kanan
    glColor3ub(105, 141, 165);
    glVertex2d(345,335.5);
    glVertex2d(351,339);
    glVertex2d(351,385);
    glVertex2d(345,381.5);
    glEnd();
    glBegin(GL_QUADS); //depan
    glColor3ub(105, 141, 165);
    glVertex2d(351,339);
    glVertex2d(481,264);
    glVertex2d(481,310);
    glVertex2d(351,385);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(345,335.5);
    glVertex2d(475,260.5);
    glVertex2d(481,264);
    glVertex2d(351,339);
    glEnd();
    glBegin(GL_LINE_LOOP); //samping kanan
    glColor3ub(0, 0, 0);
    glVertex2d(345,335.5);
    glVertex2d(351,339);
    glVertex2d(351,385);
    glVertex2d(345,381.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //depan
    glColor3ub(0, 0, 0);
    glVertex2d(351,339);
    glVertex2d(481,264);
    glVertex2d(481,310);
    glVertex2d(351,385);
    glEnd();

    //plank atas pintu kiri
    glBegin(GL_QUADS); //atas
    glColor3ub(105, 141, 165);
    glVertex2d(424.5,382.5);
    glVertex2d(477,352);
    glVertex2d(483,355.5);
    glVertex2d(430.5,386);
    glEnd();
    glBegin(GL_QUADS); //samping kanan
    glColor3ub(105, 141, 165);
    glVertex2d(425.5,382.5);
    glVertex2d(430.5,386);
    glVertex2d(430.5,412);
    glVertex2d(425.5,408.5);
    glEnd();
    glBegin(GL_QUADS); //depan
    glColor3ub(105, 141, 165);
    glVertex2d(430.5,386);
    glVertex2d(483,355.5);
    glVertex2d(483,381.5);
    glVertex2d(430.5,412);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(424.5,382.5);
    glVertex2d(477,352);
    glVertex2d(483,355.5);
    glVertex2d(430.5,386);
    glEnd();
    glBegin(GL_LINE_LOOP); //samping kanan
    glColor3ub(0, 0, 0);
    glVertex2d(425.5,382.5);
    glVertex2d(430.5,386);
    glVertex2d(430.5,412);
    glVertex2d(425.5,408.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //depan
    glColor3ub(0, 0, 0);
    glVertex2d(430.5,386);
    glVertex2d(483,355.5);
    glVertex2d(483,381.5);
    glVertex2d(430.5,412);
    glEnd();

    //gardu listrik
    glBegin(GL_QUADS); //atas
    glColor3ub(106, 138, 157);
    glVertex2d(389.5,460.5);
    glVertex2d(405,451.5);
    glVertex2d(414.5,457);
    glVertex2d(399,466);
    glEnd();
    glBegin(GL_QUADS); //samping kanan
    glColor3ub(106, 138, 157);
    glVertex2d(389.5,460.5);
    glVertex2d(399,466);
    glVertex2d(399,502.5);
    glVertex2d(389.5,497);
    glEnd();
    glBegin(GL_QUADS); //depan
    glColor3ub(106, 138, 157);
    glVertex2d(399,466);
    glVertex2d(414.5,457);
    glVertex2d(414.5,493.5);
    glVertex2d(399,502.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(389.5,460.5);
    glVertex2d(405,451.5);
    glVertex2d(414.5,457);
    glVertex2d(399,466);
    glEnd();
    glBegin(GL_LINE_LOOP); //samping kanan
    glColor3ub(0, 0, 0);
    glVertex2d(389.5,460.5);
    glVertex2d(399,466);
    glVertex2d(399,502.5);
    glVertex2d(389.5,497);
    glEnd();
    glBegin(GL_LINE_LOOP); //depan
    glColor3ub(0, 0, 0);
    glVertex2d(399,466);
    glVertex2d(414.5,457);
    glVertex2d(414.5,493.5);
    glVertex2d(399,502.5);
    glEnd();

    //plank samping pintu kiri
    glBegin(GL_QUADS); //atas
    glColor3ub(121, 247, 243);
    glVertex2d(420,434.5);
    glVertex2d(429.5,429);
    glVertex2d(434,431.5);
    glVertex2d(424.5,437);
    glEnd();
    glBegin(GL_QUADS); //samping kanan
    glColor3ub(121, 247, 243);
    glVertex2d(420,434.5);
    glVertex2d(424.5,437);
    glVertex2d(424.5,481);
    glVertex2d(420.5,478.5);
    glEnd();
    glBegin(GL_QUADS); //depan
    glColor3ub(121, 247, 243);
    glVertex2d(424.5,437);
    glVertex2d(434,431.5);
    glVertex2d(434,475.5);
    glVertex2d(424.5,481);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(420,434.5);
    glVertex2d(429.5,429);
    glVertex2d(434,431.5);
    glVertex2d(424.5,437);
    glEnd();
    glBegin(GL_LINE_LOOP); //samping kanan
    glColor3ub(0, 0, 0);
    glVertex2d(420,434.5);
    glVertex2d(424.5,437);
    glVertex2d(424.5,481);
    glVertex2d(420.5,478.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //depan
    glColor3ub(0, 0, 0);
    glVertex2d(424.5,437);
    glVertex2d(434,431.5);
    glVertex2d(434,475.5);
    glVertex2d(424.5,481);
    glEnd();

    //stop kontak
    glBegin(GL_QUADS); //atas
    glColor3ub(106, 138, 157);
    glVertex2d(389.5,416.5);
    glVertex2d(395.5,413);
    glVertex2d(399,415);
    glVertex2d(393,418.5);
    glEnd();
    glBegin(GL_QUADS); //samping kanan
    glColor3ub(106, 138, 157);
    glVertex2d(389.5,416.5);
    glVertex2d(393,418.5);
    glVertex2d(393,429.5);
    glVertex2d(389.5,427.5);
    glEnd();
    glBegin(GL_QUADS); //depan
    glColor3ub(106, 138, 157);
    glVertex2d(393,418.5);
    glVertex2d(399,415);
    glVertex2d(399,426);
    glVertex2d(393,429.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(389.5,416.5);
    glVertex2d(395.5,413);
    glVertex2d(399,415);
    glVertex2d(393,418.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //samping kanan
    glColor3ub(0, 0, 0);
    glVertex2d(389.5,416.5);
    glVertex2d(393,418.5);
    glVertex2d(393,429.5);
    glVertex2d(389.5,427.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //depan
    glColor3ub(0, 0, 0);
    glVertex2d(393,418.5);
    glVertex2d(399,415);
    glVertex2d(399,426);
    glVertex2d(393,429.5);
    glEnd();

    //loket
    //dudukan
    glBegin(GL_POLYGON); //dudukan meja kanan
    glColor3ub(138, 4, 77);
    glVertex2d(346.5,501);
    glVertex2d(357,507);
    glVertex2d(357,527);
    glVertex2d(346.5,521);
    glEnd();
    glBegin(GL_POLYGON); //dudukan meja depan
    glColor3ub(138, 4, 77);
    glVertex2d(357,507);
    glVertex2d(383,492);
    glVertex2d(383,512);
    glVertex2d(357,527);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //dudukan meja kanan
    glColor3ub(0, 0, 0);
    glVertex2d(346.5,501);
    glVertex2d(357,507);
    glVertex2d(357,527);
    glVertex2d(346.5,521);
    glEnd();
    glBegin(GL_LINE_LOOP); //dudukan meja depan
    glColor3ub(0, 0, 0);
    glVertex2d(357,507);
    glVertex2d(383,492);
    glVertex2d(383,512);
    glVertex2d(357,527);
    glEnd();

    //meja
    glBegin(GL_QUADS); //pinggir kanan
    glColor3ub(138, 4, 77);
    glVertex2d(342.5,494.5);
    glVertex2d(357,503);
    glVertex2d(357,507.5);
    glVertex2d(342.5,499);
    glEnd();
    glBegin(GL_QUADS); //pinggir depan
    glColor3ub(138, 4, 77);
    glVertex2d(357,503);
    glVertex2d(387,485.5);
    glVertex2d(387,490);
    glVertex2d(357,507.5);
    glEnd();
    glBegin(GL_QUADS); //atas meja
    glColor3ub(138, 4, 77);
    glVertex2d(342.5,494.5);
    glVertex2d(372.5,477);
    glVertex2d(387,485.5);
    glVertex2d(357,503);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //pinggir kanan
    glColor3ub(0, 0, 0);
    glVertex2d(342.5,494.5);
    glVertex2d(357,503);
    glVertex2d(357,507.5);
    glVertex2d(342.5,499);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir depan
    glColor3ub(0, 0, 0);
    glVertex2d(357,503);
    glVertex2d(387,485.5);
    glVertex2d(387,490);
    glVertex2d(357,507.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //atas meja
    glColor3ub(0, 0, 0);
    glVertex2d(342.5,494.5);
    glVertex2d(372.5,477);
    glVertex2d(387,485.5);
    glVertex2d(357,503);
    glEnd();

    //garis garis tiang loket
    glBegin(GL_LINES);
    glVertex2d(356.5,468);
    glVertex2d(356.5,501);
    glVertex2d(383.5,452.5);
    glVertex2d(383.5,485.5);
    glEnd();

    //atap
    glBegin(GL_POLYGON); //atap
    glColor3ub(234, 3, 55);
    glVertex2d(342.5,449);
    glVertex2d(372.5,432);
    glVertex2d(387,448);
    glVertex2d(387,454);
    glVertex2d(357,471);
    glVertex2d(357,465);
    glEnd();
    glBegin(GL_QUADS); //pinggiran atap
    glColor3ub(234, 3, 55);
    glVertex2d(342.5,449);
    glVertex2d(357,465);
    glVertex2d(357,471);
    glVertex2d(342.5,462.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atap
    glColor3ub(0, 0, 0);
    glVertex2d(342.5,449);
    glVertex2d(372.5,432);
    glVertex2d(387,448);
    glVertex2d(387,454);
    glVertex2d(357,471);
    glVertex2d(357,465);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggiran atap
    glColor3ub(0, 0, 0);
    glVertex2d(342.5,449);
    glVertex2d(357,465);
    glVertex2d(357,471);
    glVertex2d(342.5,462.5);
    glEnd();

}

void DekorasiTembokKanan(){
    //kotak kabel bawah pink
    glBegin(GL_QUADS);
    glColor3ub(255, 198, 248);
    glVertex2d(190.5,405);
    glVertex2d(197.5,409);
    glVertex2d(197.5,421.5);
    glVertex2d(190.5,417.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2d(190.5,405);
    glVertex2d(197.5,409);
    glVertex2d(197.5,421.5);
    glVertex2d(190.5,417.5);
    glEnd();

    //kotak kabel atas
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2d(303,365);
    glVertex2d(310,369);
    glVertex2d(310,375);
    glVertex2d(303,371);
    glEnd();

    //atasan jendela bawah
    glBegin(GL_QUADS); //atas
    glColor3ub(107, 10, 107);
    glVertex2d(254,438);
    glVertex2d(261.5,433.5);
    glVertex2d(316,465);
    glVertex2d(308.5,469.5);
    glEnd();
    glBegin(GL_QUADS); //pinggir
    glColor3ub(107, 10, 107);
    glVertex2d(308.5,469.5);
    glVertex2d(316,465);
    glVertex2d(316,469);
    glVertex2d(308.5,473.5);
    glEnd();
    glBegin(GL_QUADS); //muka
    glColor3ub(198, 26, 126);
    glVertex2d(254,438);
    glVertex2d(308.5,469.5);
    glVertex2d(308.5,481.5);
    glVertex2d(254,450);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(254,438);
    glVertex2d(261.5,433.5);
    glVertex2d(316,465);
    glVertex2d(308.5,469.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir
    glColor3ub(0, 0, 0);
    glVertex2d(308.5,469.5);
    glVertex2d(316,465);
    glVertex2d(316,469);
    glVertex2d(308.5,473.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //muka
    glColor3ub(0, 0, 0);
    glVertex2d(254,438);
    glVertex2d(308.5,469.5);
    glVertex2d(308.5,481.5);
    glVertex2d(254,450);
    glEnd();

    //plank atas pintu
    glBegin(GL_QUADS); //atas
    glColor3ub(121, 247, 243);
    glVertex2d(202,375.5);
    glVertex2d(206.5,373);
    glVertex2d(294.5,424);
    glVertex2d(290,426.5);
    glEnd();
    glBegin(GL_QUADS); //pinggir
    glColor3ub(121, 247, 243);
    glVertex2d(290,426.5);
    glVertex2d(294.5,424);
    glVertex2d(294.5,447.5);
    glVertex2d(290,450);
    glEnd();
    glBegin(GL_QUADS); //muka
    glColor3ub(121, 247, 243);
    glVertex2d(202,375.5);
    glVertex2d(290,426.5);
    glVertex2d(290,450);
    glVertex2d(202,399);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(202,375.5);
    glVertex2d(206.5,373);
    glVertex2d(294.5,424);
    glVertex2d(290,426.5);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir
    glColor3ub(0, 0, 0);
    glVertex2d(290,426.5);
    glVertex2d(294.5,424);
    glVertex2d(294.5,447.5);
    glVertex2d(290,450);
    glEnd();
    glBegin(GL_LINE_LOOP); //muka
    glColor3ub(0, 0, 0);
    glVertex2d(202,375.5);
    glVertex2d(290,426.5);
    glVertex2d(290,450);
    glVertex2d(202,399);
    glEnd();

    //plank pinggir kanan
    //penyangga atas
    glBegin(GL_QUADS); //atas
    glColor3ub(11, 13, 62);
    glVertex2d(186.5,289);
    glVertex2d(195,284);
    glVertex2d(198.5,286);
    glVertex2d(190,291);
    glEnd();
    glBegin(GL_QUADS); //pinggir
    glColor3ub(11, 13, 62);
    glVertex2d(190,291);
    glVertex2d(198.5,286);
    glVertex2d(198.5,291);
    glVertex2d(190,296);
    glEnd();
    //penyangga bawah
    glBegin(GL_QUADS); //atas
    glColor3ub(11, 13, 62);
    glVertex2d(186.5,373);
    glVertex2d(195,368);
    glVertex2d(198.5,370);
    glVertex2d(190,375);
    glEnd();
    glBegin(GL_QUADS); //pinggir
    glColor3ub(11, 13, 62);
    glVertex2d(190,375);
    glVertex2d(198.5,370);
    glVertex2d(198.5,375);
    glVertex2d(190,380);
    glEnd();
    //outline
    //penyangga atas
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(186.5,289);
    glVertex2d(195,284);
    glVertex2d(198.5,286);
    glVertex2d(190,291);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir
    glColor3ub(0, 0, 0);
    glVertex2d(190,291);
    glVertex2d(198.5,286);
    glVertex2d(198.5,291);
    glVertex2d(190,296);
    glEnd();
    //penyangga bawah
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(186.5,373);
    glVertex2d(195,368);
    glVertex2d(198.5,370);
    glVertex2d(190,375);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir
    glColor3ub(0, 0, 0);
    glVertex2d(190,375);
    glVertex2d(198.5,370);
    glVertex2d(198.5,375);
    glVertex2d(190,380);
    glEnd();

    //plank
    glBegin(GL_QUADS); //atas
    glColor3ub(45, 47, 124);
    glVertex2d(157,282.5);
    glVertex2d(182,268);
    glVertex2d(190,272.5);
    glVertex2d(165,287);
    glEnd();
    glBegin(GL_QUADS); //pinggir kanan
    glColor3ub(45, 47, 124);
    glVertex2d(157,282.5);
    glVertex2d(165,287);
    glVertex2d(165,404.5);
    glVertex2d(157,400);
    glEnd();
    glBegin(GL_QUADS); //muka depan
    glColor3ub(30, 44, 160);
    glVertex2d(165,287);
    glVertex2d(190,272.5);
    glVertex2d(190,390);
    glVertex2d(165,404.5);
    glEnd();
    //outline
    glBegin(GL_LINE_LOOP); //atas
    glColor3ub(0, 0, 0);
    glVertex2d(157,282.5);
    glVertex2d(182,268);
    glVertex2d(190,272.5);
    glVertex2d(165,287);
    glEnd();
    glBegin(GL_LINE_LOOP); //pinggir kanan
    glColor3ub(0, 0, 0);
    glVertex2d(157,282.5);
    glVertex2d(165,287);
    glVertex2d(165,404.5);
    glVertex2d(157,400);
    glEnd();
    glBegin(GL_LINE_LOOP); //muka depan
    glColor3ub(0, 0, 0);
    glVertex2d(165,287);
    glVertex2d(190,272.5);
    glVertex2d(190,390);
    glVertex2d(165,404.5);
    glEnd();
}

void TulisanGlowing(){
    glLineWidth(3.0f);
    //G64180077
    glBegin(GL_LINE_STRIP); //G
    glColor3ub(121, 247, 243);
    glVertex2d(363,340.5);
    glVertex2d(357,343.5);
    glVertex2d(353,360);
    glVertex2d(353,374.5);
    glVertex2d(363,369);
    glVertex2d(363,360);
    glVertex2d(358.5,362.5);
    glEnd();

    glBegin(GL_LINE_STRIP); //6
    glColor3ub(121, 247, 243);
    glVertex2d(377.5,332);
    glVertex2d(367.5,337.5);
    glVertex2d(367.5,366);
    glVertex2d(377.5,360.5);
    glVertex2d(377.5,346);
    glVertex2d(367.5,351.5);
    glEnd();

    glBegin(GL_LINE_STRIP); //4
    glColor3ub(121, 247, 243);
    glVertex2d(382,329);
    glVertex2d(382,343);
    glVertex2d(392,337.5);
    glVertex2d(392,323.5);
    glVertex2d(392,353);
    glEnd();

    glBegin(GL_LINE_STRIP); //1
    glColor3ub(121, 247, 243);
    glVertex2d(398.5,326);
    glVertex2d(402,317.5);
    glVertex2d(402,346.5);
    glVertex2d(396.5,349.5);
    glVertex2d(406.5,344);
    glEnd();

    glBegin(GL_LINE_LOOP); //8
    glColor3ub(121, 247, 243);
    glVertex2d(421,321);
    glVertex2d(421,307);
    glVertex2d(411,312.5);
    glVertex2d(411,341);
    glVertex2d(421,335.5);
    glVertex2d(421,321);
    glVertex2d(411,326.5);
    glEnd();

    glBegin(GL_LINE_LOOP); //0
    glColor3ub(121, 247, 243);
    glVertex2d(425.5,304);
    glVertex2d(435.5,298.5);
    glVertex2d(435.5,327.5);
    glVertex2d(425.5,333);
    glEnd();

    glBegin(GL_LINE_LOOP); //0
    glColor3ub(121, 247, 243);
    glVertex2d(440,295.5);
    glVertex2d(450,290);
    glVertex2d(450,319);
    glVertex2d(440,324.5);
    glEnd();

    glBegin(GL_LINE_STRIP); //7
    glColor3ub(121, 247, 243);
    glVertex2d(454.5,287.5);
    glVertex2d(464.5,282);
    glVertex2d(464.5,292);
    glVertex2d(459.5,313.5);
    glEnd();

    glBegin(GL_LINE_STRIP); //7
    glColor3ub(121, 247, 243);
    glVertex2d(469,279);
    glVertex2d(479,273.5);
    glVertex2d(479,284);
    glVertex2d(474,305);
    glEnd();
}
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
    doIfGeser(xpos, ypos);

}
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    double posx, posy;
    glfwGetCursorPos(window, &posx, &posy);
    a.onButtonPressed(button, action, posx, posy);
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
    glOrtho(0, 720, 720, 0, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
void display(){
    if(pencet == -1){
        glClearColor(41.0/255.0f, 49.0/255.0f, 86.0/255.0f, 1.0f); //warna background
    }
    else{
        glClearColor(159.0/255.0f, 216.0/255.0f, 255.0/255.0f, 1.0f); //warna background
    }

    glClear(GL_COLOR_BUFFER_BIT);



    glPushMatrix();
        glTranslated(367, 282, 0); // buat koordinat yaxis, xaxis pusat rotate
        glRotatef(((float)glfwGetTime())*100,0.0f,0.0f,1.0f);
        glTranslated(-367 , -282, 0); // mines yaxis, xaxis pusat rotate
        //BalingGedeAll();
    glPopMatrix();

    a.TombolLampu();
    glTranslatef(0, sin(glfwGetTime()) * -30, 0);
    Api123();
    Teras();
    AtapKiri();
    Bangunan();
    GarisGaris();
    JendelaDepan123();
    AtapKanan();
    Atap();
    KabelKabel();
    DekorasiTeras();
    Trotoar12();
    DekorasiTembokDepan();
    DekorasiTembokKanan();
    TulisanGlowing();

    glFlush();
}
int main(void) {
        //Window
        GLFWwindow* window;
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())exit(EXIT_FAILURE);
        window = glfwCreateWindow(720, 720, "Rumah Terbang Alwi", NULL, NULL);

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
