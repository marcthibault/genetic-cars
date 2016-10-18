// DO NOT COMPILE
// DO NOT EXECUTE
// YA SICK FAK

int main(int argc, char const *argv[]) {

  world = new Genetic::world;
  UI = new UI::UI;
  afficher(UI);

  while(1)
  {
// entrées user
    if(press pause)
    {
      pause = !pause;
    }

    if(change gravity)
    {
      gravity = gravity_input;
      Physique::world.change_gravity(gravity);
    }

// actions à prendre
    if(start)
    {
      injecter voitures;
      start = false;
    }

    if(termine)
    {
      scores = Genetic::scores(new positions)
      voitures = Genetic::genetic(scores, voitures)
      std::cout << "fin de course, ca repart" << std::endl;
      start = true;
    }

// boucle générale
    if(!pause)
    {
      world.nextstep();
      new_postions = Physique::newpositions(world);
      if(abs(new_position - old_position) < epsilon)
        {
          termine = true
        }
      UI::afficher(new position);
    }


  }

  return 0;
}
