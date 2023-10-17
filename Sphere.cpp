#include "Sphere.h"

void Sphere::Draw() {
		const uint32_t kSubdivision = 16;
		const float kLonEvery = (2 * pi) / kSubdivision;
		const float kLatEvery = (pi) / kSubdivision;

		for (uint32_t latIndex = 0; latIndex < kSubdivision; ++latIndex) {
			float lat = -pi / 2.0f + kLatEvery * latIndex;

			for (uint32_t lonIndex = 0; lonIndex < kSubdivision; ++lonIndex) {
				uint32_t start = (latIndex * kSubdivision + lonIndex);
				float lon = lonIndex * kLonEvery;

				//1
				spData[start].first.Left_.position.x = cos(lat) * cos(lon);
				spData[start].first.Left_.position.y = sin(lat);
				spData[start].first.Left_.position.z = cos(lat) * sin(lon);
				spData[start].first.Left_.position.w = 1.0f;

				spData[start].first.Top_.position.x = cos(lat + kLatEvery) * cos(lon);
				spData[start].first.Top_.position.y = sin(lat + kLatEvery);
				spData[start].first.Top_.position.z = cos(lat + kLatEvery) * cos(lat + kLatEvery) * sin(lon);
				spData[start].first.Top_.position.w = 1.0f;

				spData[start].first.Right_.position.x = cos(lat) * cos(lon + kLonEvery);
				spData[start].first.Right_.position.y = sin(lat);
				spData[start].first.Right_.position.z = cos(lat) * sin(lon + kLonEvery);
				spData[start].first.Right_.position.w = 1.0f;

				//2
				spData[start].second.Left_.position.x = cos(lat + kLatEvery) * cos(lon);
				spData[start].second.Left_.position.y = sin(lat + kLatEvery);
				spData[start].second.Left_.position.z = cos(lat + kLatEvery) * cos(lat + kLatEvery) * sin(lon);
				spData[start].second.Left_.position.w = 1.0f;

				spData[start].second.Top_.position.x = cos(lat + kLatEvery) * cos(lon + kLonEvery);
				spData[start].second.Top_.position.y = sin(lat + kLatEvery);
				spData[start].second.Top_.position.z = cos(lat + kLatEvery) * sin(lon + kLonEvery);
				spData[start].second.Top_.position.w = 1.0f;

				spData[start].second.Right_.position.x = cos(lat) * cos(lon + kLonEvery);
				spData[start].second.Right_.position.y = sin(lat);
				spData[start].second.Right_.position.z = cos(lat) * sin(lon + kLonEvery);
				spData[start].second.Right_.position.w = 1.0f;

			}
		}
}