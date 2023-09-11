import { Component, OnInit } from '@angular/core';
import { FaceSnap } from './models/face-snap.model';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent implements OnInit {
  mySnap!: FaceSnap[];

  ngOnInit() {
    this.mySnap = [
		{
		title: 'Archibald',
		description: 'Mon meilleur ami depuis tout petit !',
		imageUrl: 'https://cdn.pixabay.com/photo/2017/08/02/10/01/halloween-2570583_960_720.jpg',
		createdDate: new Date(),
		snaps: 20
		},
		{
			title: 'Greg',
			description: 'Mon meilleur ami depuis tout petit aussi incroyable on a presque le meme !',
			imageUrl: 'https://img.le-dictionnaire.com/monstre.jpg',
			createdDate: new Date(),
			snaps: 50,
			location: "Paris"
	  	}
	];
  }
}