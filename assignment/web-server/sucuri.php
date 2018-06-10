<?php
require('curl.php');

class SucuriAPI {
	function init() {
		
	}
	function credentials() {
		if (!isset($this->credentials)) {
			$json = file_get_contents('sucuri_api_credentials.json');
			$this->credentials = json_decode($json);
		}
		return $this->credentials;
	}
	function clear_cache() {
		foreach ($this->credentials() as $cred) {
			$curl = new SCCurl('https://waf.sucuri.net/api');
			$response = $curl->get([
				'v2' => '',
				'k' => $cred->key,
				's' => $cred->secret,
				'a' => 'clear_cache',
			]);
			break;
		}
	}
}

class ParticleAPI {
	private static $api_uri = 'https://api.particle.io';
	private static $username = 'tim@tattsy.com';
	private static $password = 'VGF0LjA5NDEq';
	function init() {

	}
	function access_token() {
		if (!isset($this->access_token)) {
			$curl = new SCCurl(self::$api_uri . '/oauth/token');
			$curl->user('particle:particle');
			$response = $curl->post([
				'grant_type' => 'password',
				'username' => self::$username,
				'password' => base64_decode(self::$password),
			]);
			$response = json_decode($response);
			$this->access_token = $response->access_token;
		}
		return $this->access_token;
	}
	function publish($event_name) {
		$curl = new SCCurl(self::$api_uri . '/v1/devices/events');
		$response = $curl->post([
			'access_token' => $this->access_token(),
			'name' => $event_name,
		]);
		$response = json_decode($response);
		return $response->ok == true;
	}
}

$sucuri = new SucuriAPI();
echo $sucuri->clear_cache();

$particle = new ParticleAPI();
$particle->publish('cacheStatus');

error_log('Cache Cleared');