camera = CurrentCamera;

current = 0;
waypoints = {
--    x  y  z  aX, aY, aZ
 	{ 0, 0, 30, 0, 0, 0 },
 	{ 0, 0, 50, 0, 0, 0 },
 	{ -20, 0, 50, 0, 20, 0 },
 	{ -20, 10, 50, 20, 0, 0 }
};
waypointsCnt = #waypoints;
speed = 1000; speedAngle = 2000;

-- initial camera position
camera.position = Vector3:new(0, 0, 30);

incX = 0; incY = 0; incZ = 0; incAngleX = 0; incAngleY = 0; incAngleZ = 0;
targetX = 0; targetY = 0; targetZ = 0; targetAngleX = 0; targetAngleY = 0; targetAngleZ = 0;

function updateTarget()
	current = current + 1;
	if (current > waypointsCnt) then current = 1; end;
	
	targetX = waypoints[current][1];
	targetY = waypoints[current][2];
	targetZ = waypoints[current][3];
	
	targetAngleX = waypoints[current][4];
	targetAngleY = waypoints[current][5];
	targetAngleZ = waypoints[current][6];
		
	local pos = camera.position;
	incX = (targetX - pos.x) / speed;
	incY = (targetY - pos.y) / speed;
	incZ = (targetZ - pos.z) / speed;
	
	local rot = camera.rotation;
	incAngleX = (targetAngleX - rot.x) / speedAngle;
	incAngleY = (targetAngleY - rot.y) / speedAngle;
	incAngleZ = (targetAngleZ - rot.z) / speedAngle;
end

-- initial update
updateTarget();

function update()
	local vec = camera.position;
	local okX = false;
	local okY = false;
	local okZ = false;
	
	if math.abs(vec.x - targetX) < 0.1 then
		okX = true;
	else
		vec.x = vec.x + incX;
	end;
	
	if math.abs(vec.y - targetY) < 0.1 then
		okY = true;
	else
		vec.y = vec.y + incY;
	end;
	
	if math.abs(vec.z - targetZ) < 0.1 then
		okZ = true;
	else
		vec.z = vec.z + incZ;
	end;
	
	camera.position = vec;

	local rot = camera.rotation;
	local okAX = false;
	local okAY = false;
	local okAZ = false;
	
	if math.abs(rot.x - targetAngleX) < 0.1 then
		okAX = true;
	else
		rot.x = rot.x + incAngleX;
	end;
	
	if math.abs(rot.y - targetAngleY) < 0.1 then
		okAY = true;
	else
		rot.y = rot.y + incAngleY;
	end;
	
	if math.abs(rot.z - targetAngleZ) < 0.1 then
		okAZ = true;
	else
		rot.z = rot.z + incAngleZ;
	end;
	
	camera.rotation = rot;
	
	if (okX == true and okY == true and okZ == true and
		okAX == true and okAY == true and okAZ == true) then
		updateTarget();
	end;
	
end