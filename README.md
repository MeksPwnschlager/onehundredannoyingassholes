# onehundredannoyingassholes 

This is the story of how I made ~100 small, annoying and relatively cheap buzzer throwies. 

## The Idea

I actually didn't know something like this existed already until I looked it up. Although I could have expected it to, in light of human mischief.
I still didn't find a version I liked.

[This one](http://www.instructables.com/id/Buzzer-Throwie/) for example, is just a battery taped to a piezo speaker, which means it's active all the time and will be easily found.
A friend of mine apperently also built [something similar](https://chaosfield.at/projects/annoyotron.html), although it is not designed for "mass"-production. He even used an Attiny13 and wrote all the code directly in C, instead of using something like the Arduino IDE.
[The Annoy-O-Bug](https://www.hackster.io/AlexWulff/the-annoy-o-bug-a-chirping-light-up-throwie-37e58a) is a little different, it has a small mircocontroller and an LED. It uses the Attiny85. The undesired side-effect: One of theses costs almost 5 Euros.

I knew I had to make it more affordable, so I consulted with a few of my electronics-affine friends.
Our first instinct was to use two timers, one for the long intervals between beeps and one for the PWM for the piezo speaker.
Upon looking it up, we found that an Attiny25 was actually cheaper, so we went for that.

## The Prototype

[Overflo](https://github.com/overflo23), who owns [hackerspaceshop.com](https://hackerspaceshop.com) sent me a bunch of components to build a prototype. What an incredibly nice man!

It was like Christmas!
![It was like Christmas!](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/overflos_care_package.jpg)


The first PCB was designed by [Amir](https://github.com/kallaballa) in a CAD program and home-made at our local hackerspace [Metalab](http://metalab.at).

We used spraypaint for the mask, which we removed with a LASER-Cutter where we wanted the copper to dissolve.
![Spray](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/etching_spray.jpg)
![Lazzzored](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/etching_lazzzored.jpg)


Mixing the acid:
![Mixing](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/etching_mixing_acid.jpg)


And in it goes!
![Nice Warm Bath](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/etching_acid_bath.jpg)


Metalab's heater for the acid bath was pretty broken, so we tried to build a new one:
![New Heater](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/etching_new_heater.jpg)


But that didn't work aswell, so I just sat there with a hot-air-gun to keep it from getting too chilly.

Needless to say, we noticed a mistake in the design right after it was done etching.
Thankfully this was easily fixable:
![Easily fixable](https://raw.githubusercontent.com/MeksPwnschlager/onehundredannoyingassholes/master/img/etching_fixed_prototype.jpg)


We still wanted a proper PCB so we did it all again with a fixed design.

[This was the finished Prototype](https://www.youtube.com/watch?v=84bH-g-eUzU)
