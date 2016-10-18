# Genetic Cars

This is the Genetic Cars Git repository.


Here is the link to the dream we have to reproduce : 

http://rednuht.org/genetic_cars_2/

And a preview :

![alt text](http://www.similars.io/img/logo/genetic-cars-2_35110.png "Logo Title Text 1")


## Git tuto
Here's how to use Git : 

- Install *Git*

    Just type on Google `install git pc/mac/linux`

- Install *SourceTree*

    Just type on Google `install sourcetree pc/mac/linux`
    
- Clone the repository

    Click on "Clone"
    
    As a project url, type `https://gitlab.binets.fr/marc.thibault/genetic-cars.git`
    
    You will be asked your LDAP IDs, just type them in
    
    You have successfully cloned the whole project !
    
## Git workflow

Here's the workflow we'll be using : 

As you start working, update your repository by pulling the server repository : 

`git pull origin master`

`git pull origin mybranch`

Do your modifications on the source code. You can then add them to your local branch : 

`git add --all`

`git commit -m 'my_commit_comment'`

`git push origin mybranch`

As you think your branch is cool enough to replace the master branch, go to Gitlab and do a merge request. The team leader then has to accept the merge request.
