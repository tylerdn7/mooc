SELECT DISTINCT movie.year FROM movie 
WHERE EXISTS (SELECT DISTINCT rating.stars FROM rating WHERE (rating.mID = movie.mID)
AND (rating.stars = 4 OR rating.stars = 5));
