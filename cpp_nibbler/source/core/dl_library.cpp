//
// dl_library.cpp for dl_library.cpp in /home/faisant/Bureau/projet/cpp_nibbler
// 
// Made by florian faisant
// Login   <faisant@epitech.net>
// 
// Started on  Mon Mar 31 21:27:26 2014 florian faisant
// Last update Tue Apr  1 19:19:22 2014 florian faisant
//

#include	<dlfcn.h>
#include	<string>
#include	"core/dl_lib.hpp"
#include	"core/exception.hpp"

Dl_library::Dl_library(const std::string &path)
{
  this->handle = dlopen(path.c_str(), RTLD_NOW);
  if (this->handle == NULL)
    {
      std::string error_msg = "Impossible de charger la librairie " + path + " : " + std::string(dlerror());
      throw core_exception(error_msg);
    }
}

ILib	*Dl_library::get_lib()
{
  ILib *(*factory)() = (ILib *(*)()) (dlsym(this->handle, "createLib"));
  if (factory == NULL)
    throw core_exception("Impossible de trouver createLib");
  ILib *lib = factory();
  if (lib == NULL)
    throw core_exception("Impossible de récupérer l'instance de la classe");
  return (lib);
}

Dl_library::~Dl_library()
{
  if (this->handle != NULL)
    dlclose(this->handle);
}
