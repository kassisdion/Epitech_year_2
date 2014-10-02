//
// mapEditorSize.cpp for bomberman in /home/alice/Epitech/2017/Teck2/C++/BomberMan/BomberManLocal/MapEditor/EditorMap
// 
// Made by alice groux
// Login   <groux_a@epitech.net>
// 
// Started on  Mon Jun  2 17:55:27 2014 alice groux
// Last update Sat Jun 14 13:16:09 2014 florian faisant
//

#include		<string>
#include		<iostream>
#include		<nds.h>

#include        "core/views/EditorView.hpp"
#include        "EditorMap/mapEditor.hpp"
#include        "EditorMap/mapEditorSize.hpp"
#include        "graphics/editeurSize.h"
#include        "core/views/menu.hpp"
#include        "core/screens.hpp"

static Menu::MenuItem *createItems()
{
    static Menu::MenuItem items[] = {
        Menu::MenuItem(Menu::MenuItem::ItemRect(7, 4, 120, 35)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(7, 51, 120, 35)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(7, 101, 120, 35)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(131, 4, 120, 35)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(131, 51, 120, 35)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(131, 100, 120, 35)),
        Menu::MenuItem(Menu::MenuItem::ItemRect(71, 150, 120, 35)),
    };
    return items;
}

MapEditorSize::MapEditorSize(MenuView *view) :
    Menu(createItems(), 7, view, editeurSizeBitmap, editeurSizeBitmapLen)
{
}

MapEditorSize::~MapEditorSize()
{ }

void MapEditorSize::onClick(unsigned int index, MenuItem &item)
{
    MapEditor *editor;

    switch (index)
        {
            case 0 :
            {
                editor = new MapEditor(15, 15);
            }
            break;
            case 1 :
            {
                editor = new MapEditor(25, 25);
            }
            break;
            case 2 :
            {
                editor = new MapEditor(25, 75);
            }
            break;
            case 3 :
            {
                editor = new MapEditor(50, 50);
            }
            break;
            case 4 :
            {
                editor = new MapEditor(75, 75);
            }
            break;
            case 5 :
            {
                editor = new MapEditor(50, 100);
            }
            break;
            case 6 :
            {
                editor = new MapEditor(100, 100);
            }
            break;
            default :
            {
                //BUG BUG BUG !!!
            }
            break;
        }
        Screens::lower().setView(new EditorView(editor));
}
