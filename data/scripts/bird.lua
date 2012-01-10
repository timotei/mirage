bird = CurrentComponent;

currentRotation = 0;
bird.translation.z = 10;
incRot = 0.5 + math.random();

function update()
	currentRotation = currentRotation + incRot;
	if ( currentRotation >= 360 ) then
		currentRotation = currentRotation - 360;
	elseif ( currentRotation <= -360 ) then
		currentRotation = currentRotation + 360;
	end;
	
	bird.rotation.y = currentRotation;
end