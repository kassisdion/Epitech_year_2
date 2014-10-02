#include "core/debug.hpp"
#include "core/views/Graph3D.hpp"

Graph3D::Graph3D(const Game &game, Screen *screen)
	: View(screen)
	, _game(game){
		_skyBox = new SkyBox(game.map->getSize().x(), game.map->getSize().y());
		_cam = new Cam(5.5, 1.7, 5.0f);
		_mapRender = new MapRender(game);
		_bombRender = new BombRender(game);
		_playerRender = new PlayerRender(game);
	}

Graph3D::~Graph3D(){}

void 		Graph3D::init(){
    screen->setMode(Screen::Mode::ThreeD);
	vramSetBankD(VRAM_D_ARM7_0x06000000);
	glInit();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_ANTIALIAS);
	glEnable(GL_BLEND);
    glClearColor(255, 255, 255, 31);
	glClearPolyID(63);
	glClearDepth(0x7FFF);
	glViewport(0, 0, 255, 191);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, 256.0 / 192.0, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
    glMaterialf(GL_AMBIENT, RGB15(16, 16, 16));
    glMaterialf(GL_DIFFUSE, RGB15(16, 16, 16));
    glMaterialf(GL_SPECULAR, BIT(15) | RGB15(8, 8, 8));
    glMaterialf(GL_EMISSION, RGB15(16, 16, 16));
    glMaterialShinyness();

    glPolyFmt(POLY_ALPHA(31) | POLY_CULL_NONE | POLY_FORMAT_LIGHT0 | POLY_FOG);
}

void 		Graph3D::moveCam(){
	_cam->move(_game.getPlayer().getPos().x(), _game.getPlayer().getPos().y());
}

void 		Graph3D::draw(){
	glColor3f(1, 1, 1);
	moveCam();
	_cam->lookAt();
    _skyBox->draw();
    _playerRender->drawAll();
	_mapRender->drawWall();
	_bombRender->drawAll();
	_mapRender->drawMap();
}

void 		Graph3D::display(){
	glFlush(0);
	swiWaitForVBlank();
}

void 		Graph3D::render(){
	draw();
	display();
}
