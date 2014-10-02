#ifndef CORE_VIEWS_EDITOR_H_
#define CORE_VIEWS_EDITOR_H_

#include "core/view.hpp"
#include "core/menu.hpp"
#include "EditorMap/mapEditor.hpp"
#include "core/graphics/Sprite.hpp"
#include "utils/time.hpp"

class EditorView: public View
{
public:
    EditorView(MapEditor *mapEditor);
    virtual ~EditorView();

public:
    virtual void update(const Events &events);
    virtual void render();
    void affSprite(Map::Tile tile, int x, int y, int id);

public:
    void setMenu(Menu *menu = nullptr);
    Menu &getMenu();
    const Menu &getMenu() const;

public:
    MapEditor *mapEditor;
    unsigned int x;
    unsigned int y;
    Sprite      *sprites;
    SpriteTile  dwall;
    SpriteTile  iwall;
    Clock clock;
}; 

#endif /* CORE_VIEWS_EDITOR_H_ */
