import { Component, OnInit , Input } from '@angular/core';
import { FaceSnap } from '../models/face-snap.model';

@Component({
  selector: 'app-face-snap',
  templateUrl: './face-snap.component.html',
  styleUrls: ['./face-snap.component.scss']
})

export class FaceSnapComponent{
	@Input() faceSnap!: FaceSnap

	buttonSnap!: string;

	ngOnInit() {
		this.buttonSnap = "Oh snap!";
	  }

	onSnap(){
		if (this.buttonSnap == "Oh snap!")
		{
			this.faceSnap.snaps++;
			this.buttonSnap = "Snapped";
		}
		else{
			this.faceSnap.snaps--;
			this.buttonSnap = "Oh snap!";
		}
	}
}
